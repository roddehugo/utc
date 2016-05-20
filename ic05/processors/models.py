from datetime import datetime

from processors.logger import applogger
from processors.exceptions import EmptyArgumentsError


logger = applogger(__name__)


class Model(object):

    def __init__(self, *args):
        try:
            if not args:
                raise EmptyArgumentsError(self.__class__)
        except EmptyArgumentsError, e:
            logger.error(e)
        self.values = args
        self.defaults()

    def __str__(self):
        return '<%s> [%s] (%s)' % (
            self.table,
            self.join(self.keys, '`'),
            self.join(self.values)
        )

    def val(self, key):
        return self.values[self.keys.index(key)]

    def join(self, array, apostrophe="'", delimiter=', '):
        return '%s%s%s' % (
            apostrophe,
            ('%s%s%s' % (
                apostrophe, delimiter, apostrophe
            )).join(array),
            apostrophe
        )

    def sql(self):
        return 'INSERT INTO `%s` (%s) VALUES (%s);' % (
            self.table,
            self.join(self.keys, '`'),
            self.join(self.values)
        )

    def csv(self):
        return self.join(self.values, '', ';')

    def defaults(self):
        pass

    def date_time(self, date, time):
        date = '-'.join(reversed(date.split('/')))
        return '%s %s' % (date, time)

    def time12to24(self, time):
        time = datetime.strptime(time, '%I:%M %p')
        return datetime.strftime(time, '%H:%M:%S')

    def time3to24(self, time):
        if len(time) == 3:
            time = '0%s' % time
        time = datetime.strptime(time, '%H%M')
        return datetime.strftime(time, '%H:%M:%S')


class Application(Model):
    table = 'applications'
    keys = ('application_id', 'name')

    def defaults(self):
        if not self.values[0]:
            self.values = ('0', 'Picasso')


class Buyer(Model):
    table = 'buyers'
    keys = ('buyer_id', )


class Category(Model):
    table = 'categories'
    keys = ('category_id', 'name', 'alcool')

    def defaults(self):
        if 'biere' in self.val('name').lower():
            self.values += ('1',)
        else:
            self.values += ('0',)


class Product(Model):
    table = 'products'
    keys = ('product_id', 'category_id', 'name', 'price')


class Transaction(Model):
    table = 'transactions'
    keys = ('transaction_id', 'application_id', 'buyer_id',
            'product_id', 'measurement_id', 'permanence_id', 'datetime', 'quantity', 'total')

    def defaults(self):
        if not self.val('application_id'):
            self.values = (self.val('transaction_id'), '0') + self.values[2:]
        self.values = self.values[:4] + ('NULL', 'NULL', self.date_time(self.values[4], self.values[5]),) + self.values[6:]


class Day(Model):
    table = 'days'
    keys = ('day_id', 'date', 'temp_min', 'temp_max', 'sunrise', 'sunset')

    def defaults(self):
        self.values = (str(self.values[0]),) + self.values[1:4] + (
            self.time12to24(self.values[4]), self.time12to24(self.values[5])
        )


class Weather(Model):
    table = 'weathers'
    keys = ('weather_id', 'description', 'icon')


class Measurement(Model):
    table = 'measurements'
    keys = ('measurement_id', 'weather_id', 'day_id', 'datetime', 'temperature', 'precipitation')

    def defaults(self):
        self.values = self.values[:2] + (
            str(self.values[2]), self.date_time(
                self.values[3], self.time3to24(self.values[4])
            )
        ) + self.values[5:]


class Permanence(Model):
    table = 'permanences'
    keys = ('permanence_id', 'datetime', 'duration', 'asso_name')

    def defaults(self):
        if self.values[2] == 'Matin':
            time = '10:00:00'
            duration = '30'
        elif self.values[2] == 'Midi':
            time = '12:00:00'
            duration = '120'
        elif self.values[2] == 'Soir':
            time = '18:00:00'
            duration = '300'

        asso_name = self.values[3].replace("'", '').replace('"', '')

        self.values = (self.values[0], self.date_time(self.values[1], time), duration, asso_name)
