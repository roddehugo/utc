# IC05 project — Picasso

## Getting Started

### Git repository

Clone git repository
```bash
$ git clone git@gitlab.utc.fr:roddehug/ic05-picasso.git && cd ic05-picasso
```

### Virtualenv

Install a new virtual environment in venv folder
```bash
$ virtualenv venv
```

Activate the virtual environment
```bash
$ source venv/bin/activate
```

Install requirements
```bash
$ pip install -r requirements.txt
```

### Diagrams

## Database

![Database UML](https://gitlab.utc.fr/roddehug/ic05-picasso/raw/master/site/static/public/images/database.png)

## Packages

![Packages UML](https://gitlab.utc.fr/roddehug/ic05-picasso/raw/master/site/static/public/images/packages.png)

## Classes

![Classes UML](https://gitlab.utc.fr/roddehug/ic05-picasso/raw/master/site/static/public/images/classes.png)

## How to understand the structure

Both Parser and Merger inherit from AbstractProcessor. They implement the process method.

### Parsers

In Parsers, the process is to read from the input file and to write to the output file.

There is three kind of parser:
* Payutc (csv to sql for all payutc data)
* Weather (csv to sql for all weather data)
* Perm (csv to sql for perms)

### Mergers

In Mergers, the process is to read from a list of file or a folder, and for each file, read it and write to the output file

There is one kind of merger:
* Wheater (merges all partials in one json)

### Scrapers

There is one kinf of scraper:
* Payutc (user ids prom payutc server)

## How to run the code

Be sure to be in the main folder (it contains the main.py file).

Then you can get some help by typing:
```bash
$ python main.py -h
Usage: python main.py [-p type | -m type | -s type] -i infile -o outfile
  -p type : payutc or weather or perm
  -m type : weather
  -s type : payutc
  -i in   : input file(s) (support wildchar *)
  -o out  : output file
  -h      : show this message
```

You choose between a parser, a merger or a scraper by respectively adding the `-p`, `-m` or `-s` parameter followed by the processor's kind.

You then add the input file(s) or folder path and the output file path.

## Examples

To merge all weather partials
```bash
$ python main.py -m weahter -i data/json/partials/*.json -o data/json/weather.json
```

To parse the newly created JSON
```bash
$ python main.py -p weather -i data/json/weather.json -o data/sql/weather.sql
```

To parse the CSV
```bash
$ python main.py -p payutc -i data/csv/nouveau.csv -o data/sql/nouveau.sql
```

## Technologies

This project uses :
* python 2.7 in a virtualenv
* mysql 5.7.9

