import csv
import json

from processors.abstract import AbstractProcessor
from processors.logger import applogger
from processors.models import Application, Buyer, Category, Permanence, Product, Transaction
from processors.models import Day, Weather, Measurement


logger = applogger(__name__)


class Parser(AbstractProcessor):

    def process(self):
        with open(self.in_path, 'rb') as f:
            self.input(f)
        with open(self.out_path, 'wb') as f:
            self.output(f)

    def out_sql(self, f, dictionary):
        for k, v in dictionary.iteritems():
            f.write('%s\n' % v.sql())

    def out_start_transaction(self, f):
        f.write('START TRANSACTION;\n')

    def out_commit(self, f):
        f.write('COMMIT;\n')


class CsvParser(Parser):

    def input(self, f):
        reader = csv.DictReader(f, delimiter=';')
        for row in reader:
            for name, obj in self.objects.iteritems():
                self.in_csv(row, obj['headers'], obj['data'], obj['class'])

    def output(self, f):
        self.out_start_transaction(f)
        for name, obj in self.objects.iteritems():
            self.out_sql(f, obj['data'])
        self.out_commit(f)

    def in_csv(self, row, colums, dictionary, klass):
        try:
            col_id = row[colums[0]]
            if col_id not in dictionary.keys():
                args = (row[key] for key in colums)
                dictionary[col_id] = klass(*args)
        except (KeyError, IndexError), e:
            logger.error('%s, %s, %r %s' % (e, klass, row, colums))


class PayutcParser(CsvParser):
    objects = {
        'application': {
            'headers': ('SalesLocationID', 'SalesLocation'),
            'class': Application,
            'data': {}
        },
        'buyer': {
            'headers': ('BuyerID', ),
            'class': Buyer,
            'data': {}
        },
        'category': {
            'headers': ('CategoryID', 'Category'),
            'class': Category,
            'data': {}
        },
        'product': {
            'headers': ('ItemID', 'CategoryID', 'Item', 'UnitPriceVAT'),
            'class': Product,
            'data': {}
        },
        'transaction': {
            'headers': ('TransactionID', 'SalesLocationID', 'BuyerID', 'ItemID',
                        'TransactionDate', 'TransactionTime', 'Quantity', 'TotalPriceVAT'),
            'class': Transaction,
            'data': {}
        }
    }


class PermParser(CsvParser):
    objects = {
        'permanences': {
            'headers': ('Id', 'Date', 'Seance', 'Name_Asso'),
            'class': Permanence,
            'data': {}
        }
    }


class JsonParser(Parser):

    def output(self, f):
        self.out_start_transaction(f)
        for name, obj in self.objects.iteritems():
            self.out_sql(f, obj)
        self.out_commit(f)


class WeatherParser(JsonParser):

    objects = {
        'days': {},
        'weathers': {},
        'measurements': {}
    }

    def input(self, f):
        try:
            data = json.load(f)['weather']
        except KeyError, e:
            logger.error('%s, %s' % (e, f))

        self.days = self.objects['days']
        self.weathers = self.objects['weathers']
        self.measurements = self.objects['measurements']

        for i in range(0, len(data)):
            try:
                el = data[i]
                hourly = el['hourly']
                astro = el['astronomy'][0]
                self.days[i] = Day(i, el['date'], el['mintempC'], el['maxtempC'],
                                   astro['sunrise'], astro['sunset'])
            except (KeyError, IndexError), e:
                logger.error('%s, %s' % (e, el))

            for h in hourly:
                try:
                    weather_id = h['weatherCode']
                    if weather_id not in self.weathers:
                        self.weathers[weather_id] = Weather(weather_id, h['weatherDesc'][0]['value'],
                                                            h['weatherIconUrl'][0]['value'])
                    mea_id = '%s%s' % (i, h['time'])
                    if mea_id not in self.measurements:
                        self.measurements[mea_id] = Measurement(mea_id, weather_id, i, el['date'],
                                                                h['time'], h['tempC'], h['precipMM'])
                except (KeyError, IndexError), e:
                    logger.error('%s, %s' % (e, h))
