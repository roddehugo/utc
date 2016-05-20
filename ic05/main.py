import sys
from parse import parse

from processors.parsers import PayutcParser, PermParser, WeatherParser
from processors.mergers import WeatherMerger
from processors.scrapers import PayutcScraper

parsers = {
    'payutc': PayutcParser,
    'weather': WeatherParser,
    'perm': PermParser
}
mergers = {
    'weather': WeatherMerger
}
scrapers = {
    'payutc': PayutcScraper
}


def is_help(command):
    co = command[7:]
    return co == '-h' or co == '--help'


def help():
    print 'Usage: python main.py [-p type | -m type | -s type] -i infile -o outfile'
    print '  -p type : %s' % ' or '.join(parsers.keys())
    print '  -m type : %s' % ' or '.join(mergers.keys())
    print '  -s type : %s' % ' or '.join(scrapers.keys())
    print '  -i in   : input file(s) (support wildchar *)'
    print '  -o out  : output file'
    print '  -h      : show this message'


if __name__ == '__main__':
    command = ' '.join(sys.argv)
    args = parse("main.py -{} {} -{} {} -{} {}", command)
    if not args or is_help(command):
        help()
        exit(1)

    args = args.fixed
    args = {k: args[args.index(k)+1] for k in args[::2]}

    if 'p' in args:
        processor = parsers[args['p']]
    elif 'm' in args:
        processor = mergers[args['m']]
    elif 's' in args:
        processor = scrapers[args['s']]
    else:
        help()
        exit(1)

    processor(args['i'], args['o']).process()
