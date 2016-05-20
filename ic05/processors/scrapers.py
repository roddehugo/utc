import requests
import unicodedata

from processors.abstract import AbstractProcessor
from processors.exceptions import CookieExpiredError
from processors.logger import applogger
from processors.models import Buyer


logger = applogger(__name__)


class Scraper(AbstractProcessor):

    def process(self):
        with open(self.out_path, 'wb') as outf:
            if self.csv_headers:
                self.out_headers(outf, self.csv_headers)
            with open(self.in_path, 'rb') as inf:
                for out in self.input(inf):
                    self.output(outf, out)

    def out_csv(self, f, klass):
        f.write('%s\n' % klass.csv())

    def out_headers(self, f, array):
        f.write(';'.join(array))


class TxtScraper(Scraper):

    def input(self, f):
        for line in f:
            line = line.strip()
            url = self.url + '?q=%s' % line
            res = requests.get(url, headers=self.headers)
            yield self.process_response(res)

    def output(self, f, out):
        if out:
            self.out_csv(f, out)


class PayutcScraper(TxtScraper):
    url = 'https://payutc.nemopay.net/ajax'
    headers = {
        'cookie': 'casper=0%7CeyJjb25maWciOnsiY3VycmVuY3lfc3ltYm9sIjoiXHUyMGFjIiwidGl0bGUiOiJwYXl1dGMiLCJuYl9kZWNpbWFsIjoyfSwic2xpbS5mbGFzaCI6W10sImNhc3Blcl9qc29uX2NsaWVudF9jb29raWUiOnsic2Vzc2lvbmlkIjoic2Vzc2lvbmlkPWw1dGt1NmVuazJudnlua2psMzYwNTAyaTZ5Zm9oM24wIn19%7C42403b453247a8b482d86091b1330e8fc9f28d7d'
    }
    csv_headers = ('userId', 'userName', 'userLogin')
    ids_seen = []

    def process_response(self, res):
        try:
            user = res.json()
        except ValueError, e:
            logger.error('%s, %s' % (e, res.text))
            raise CookieExpiredError

        try:
            user = user[0]
            user_id = str(user['id'])
            if user_id not in self.ids_seen:
                self.ids_seen.append(user_id)
                user_name = user['name'][:-11]
                user_login = user['name'][-9:-1]
                user_name = unicodedata.normalize('NFKD', user_name).encode('ascii', 'ignore')
                return Buyer(user_id, user_name, user_login)
        except (IndexError, KeyError), e:
            logger.error('%s, %s' % (e, user))
