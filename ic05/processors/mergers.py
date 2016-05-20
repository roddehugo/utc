import json
import glob

from processors.abstract import AbstractProcessor
from processors.logger import applogger


logger = applogger(__name__)


class Merger(AbstractProcessor):

    def process(self):
        if len(self.in_path.split(' ')) > 1:
            files = self.in_path.split(' ')
        else:
            folder = self.in_path
            path = folder[:-1] if folder[-1] == '/' else folder
            path = "%s/*.%s" % (path, self.extension)
            files = glob.glob(path)
        for onefile in files:
            with open(onefile, "rb") as f:
                self.input(f)
        with open(self.out_path, 'wb') as f:
            self.output(f)


class JsonMerger(Merger):

    def __init__(self, in_path, out_path):
        super(JsonMerger, self).__init__(in_path, out_path)
        self.headers_are_set = False

    def output(self, f):
        result = {}
        for name, obj in self.objects.iteritems():
            result[name] = obj
        json.dump(result, f, indent=4)


class WeatherMerger(JsonMerger):

    objects = {
        'nearest_area': [],
        'weather': []
    }

    def input(self, f):
        self.nearest_area = self.objects['nearest_area']
        self.weather = self.objects['weather']
        try:
            data = json.load(f)['data']
            if not self.headers_are_set:
                self.nearest_area = data['nearest_area']
                self.headers_are_set = True
            self.weather += data['weather']
        except ValueError, e:
            logger.error('%s' % (f))
            logger.error(e)
