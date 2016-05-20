# Some interesting SQL queries and results

## Top 10

Get the ranking of buyers by amount, with transactions count, total spent, start and end date

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  MIN(`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
GROUP BY `buyer_id`
ORDER BY `sum` DESC
LIMIT 10;
```

| buyer_id | quantity | sum     | from                | to                  |
| -------- | -------- | ------  | ------------------  | ------------------- |
| 6541     | 2381     | 2135.45 | 2014-09-05 19:39:14 | 2015-06-28 19:26:25 |
| 7332     | 1562     | 1329.87 | 2014-09-08 18:54:07 | 2015-06-25 20:38:51 |
| 4816     | 1524     | 1301.14 | 2014-09-03 18:32:45 | 2015-06-19 19:47:18 |
| 4838     | 963      | 1263.58 | 2014-09-08 18:47:58 | 2015-06-27 18:33:28 |
| 4923     | 1197     | 1138.63 | 2014-09-08 10:00:34 | 2015-06-24 21:20:29 |
| 5908     | 978      | 1033.53 | 2014-09-09 16:48:33 | 2015-06-25 10:40:34 |
| 5463     | 840      | 1033.20 | 2014-09-09 14:27:59 | 2015-06-25 21:06:05 |
| 5498     | 843      | 1003.45 | 2014-09-03 18:29:41 | 2015-06-30 11:29:07 |
| 1147     | 2212     | 942.33  | 2014-10-07 19:48:19 | 2015-06-28 19:26:07 |
| 4932     | 859      | 864.55  | 2014-09-08 10:47:23 | 2015-06-25 19:27:30 |


Get the ranking of buyers by quantity, with transactions count, total spent, start and end date

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  MIN(`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
GROUP BY `buyer_id`
ORDER BY `quantity` DESC
LIMIT 10;
```

| buyer_id | quantity | sum     | from                | to                  |
| -------- | -------- | ------  | ------------------  | ------------------- |
| 71       | 6505     | 700.52  | 2014-09-08 11:27:12 | 2015-06-27 18:43:36 |
| 6541     | 2381     | 2135.45 | 2014-09-05 19:39:14 | 2015-06-28 19:26:25 |
| 1147     | 2212     | 942.33  | 2014-10-07 19:48:19 | 2015-06-28 19:26:07 |
| 7332     | 1562     | 1329.87 | 2014-09-08 18:54:07 | 2015-06-25 20:38:51 |
| 4816     | 1524     | 1301.14 | 2014-09-03 18:32:45 | 2015-06-19 19:47:18 |
| 6137     | 1441     | 383.24  | 2014-09-08 19:23:38 | 2015-05-16 20:57:10 |
| 4923     | 1197     | 1138.63 | 2014-09-08 10:00:34 | 2015-06-24 21:20:29 |
| 5743     | 992      | 601.95  | 2014-09-10 18:46:55 | 2015-06-25 21:27:42 |
| 5908     | 808      | 1033.53 | 2014-09-09 16:48:33 | 2015-06-25 10:40:34 |
| 4838     | 843      | 1263.58 | 2014-09-08 18:47:58 | 2015-06-27 18:33:28 |


Get the top 10 biggest transactions in terms of quantity, with associated product and permanence name
```sql
SELECT transactions.transaction_id, transactions.buyer_id, products.name, permanences.asso_name, transactions.datetime, transactions.quantity, transactions.total
FROM transactions 
INNER JOIN permanences
ON transactions.permanence_id = permanences.permanence_id
INNER JOIN products
ON transactions.product_id = products.product_id
WHERE total > 0
ORDER BY quantity DESC
LIMIT 10;
```

| transaction_id | buyer_id | name                   | asso_name         | datetime            | quantity | total |
| -------------- | -------- | ---------------------- | ----------------- | ------------------- | -------- | ----- |
| 386417         | 168      | Menu Perm Plep         |                   | 2014-12-18 18:28:05 | 40       | 60    |
| 431233         | 5041     | Kinder Maxi            | La Finepic        | 2015-03-12 13:14:40 | 32       | 3.2   |
| 407535         | 5103     | Barbar Blonde          | Picasso           | 2015-02-17 21:11:53 | 24       | 46.8  |
| 454541         | 5103     | Grand Cru St Feuillien | B3M               | 2015-03-26 21:33:39 | 24       | 46.8  |
| 456406         | 7283     | Rochefort 8            | P15 du Turfu      | 2015-03-27 20:24:39 | 24       | 46.8  |
| 465356         | 5432     | Chimay Bleue           | semaine des poles | 2015-04-02 21:18:55 | 24       | 43.2  |
| 467353         | 7356     | Rochefort 8            | semaine des poles | 2015-04-03 21:19:38 | 24       | 46.8  | 
| 317759         | 6442     | Duvel                  | Ski UTC           | 2014-10-07 20:20:58 | 24       | 39.6  |
| 494753         | 6008     | Duvel                  |                   | 2015-04-25 19:40:49 | 24       | 39.6  |
| 524440         | 4931     | Duvel                  | Charcutc          | 2015-05-20 21:29:44 | 24       | 39.6  |


Get the top 10 biggest transactions in terms of amount, with associated product and permanence name

```sql
SELECT transactions.transaction_id, transactions.buyer_id, products.name, permanences.asso_name, transactions.datetime, transactions.quantity, transactions.total
FROM transactions
INNER JOIN permanences
ON transactions.permanence_id = permanences.permanence_id
INNER JOIN products
ON transactions.product_id = products.product_id
ORDER BY total DESC
LIMIT 10;
```

| transaction_id | buyer_id | name                   | asso_name           | datetime            | quantity | total |
| -------------- | -------- | ---------------------- | ------------------- | ------------------- | -------- | ----- |
| 386417         | 168      | Menu Perm Plep         |                     | 2014-12-18 18:28:05 | 40       | 60    |
| 407535         | 5103     | Grand Cru St Feuillien | Picasso             | 2015-02-17 21:11:53 | 24       | 46.8  | 
| 454541         | 5103     | Grand Cru St Feuillien | B3M                 | 2015-03-26 21:33:39 | 24       | 46.8  |
| 456406         | 7283     | Rochefort 8            | P15 du Turfu        | 2015-03-27 20:24:39 | 24       | 46.8  |
| 467353         | 7356     | Rochefort 8            | semaine des poles   | 2015-04-03 21:19:38 | 24       | 46.8  |
| 465356         | 5432     | Chimay Bleue           | semaine des poles   | 2015-04-02 21:18:55 | 24       | 43.2  |
| 536571         | 5956     | Tripel Karmeliet       | DisneyCaliente      | 2015-05-29 19:55:49 | 24       | 43.2  |
| 389999         | 6176     | Carolus Triple         | Picemons            | 2014-12-22 20:45:36 | 24       | 42    |
| 357851         | 5908     | Grand Cru St Feuillien | PVDC                | 2014-11-21 21:29:32 | 21       | 40.95 |
| 368050         | 5908     | Grand Cru St Feuillien | Comedie Musicale    | 2014-12-01 19:55:50 | 21       | 40.95 |


Get the ranking of days with the biggest attendance 

```sql
SELECT  
  cast(`datetime` AS DATE) AS `date`, 
  COUNT(DISTINCT `buyer_id`) AS `nb_client`
FROM `transactions`
GROUP BY `date`
ORDER BY `nb_client` DESC
LIMIT 10;
```

| date       | nb_client |
| ---------- | --------  |
| 2015-05-13 | 1487      |
| 2015-02-16 | 1018      |
| 2014-11-10 | 950       |
| 2015-02-26 | 841       |
| 2014-12-22 | 811       |
| 2015-04-21 | 804       |
| 2015-03-13 | 798       |
| 2015-03-20 | 795       |
| 2015-02-19 | 791       |
| 2015-02-18 | 782       |


Get the ranking of days with the biggest attendance, with the corresponding permanences

```sql
SELECT  
  `permanences`.`asso_name` AS `permanence`,
  cast(`transactions`.`datetime` AS DATE) AS `date`, 
  COUNT(DISTINCT `transactions`.`buyer_id`) AS `nb_client`
FROM `transactions`
INNER JOIN `permanences`
ON cast(`transactions`.`datetime` AS DATE) = cast(`permanences`.`datetime` AS DATE)
WHERE cast(`permanences`.`datetime` AS TIME) = "18:00:00"
GROUP BY `date`
ORDER BY `nb_client` DESC
LIMIT 10;
```

| permanence           | date       | nb_client |
| -------------------- | ---------- | --------  |
| ESTU PARKING         | 2015-05-13 | 1487      |
| Picasso              | 2015-02-16 | 1018      |
| Vieux CompiBitches   | 2014-11-10 | 950       |
| Rugby UTC            | 2015-02-26 | 841       |
| Picemons             | 2014-12-22 | 811       |
| Imaginarium Festival | 2015-04-21 | 804       |
| Les Schtroumpfs      | 2015-03-13 | 798       |
| Comedie Musicale     | 2015-03-20 | 795       |
| Picasso              | 2015-02-19 | 791       |
| Picasso              | 2015-02-18 | 782       |


Get the ranking of days with the biggest revenue

```sql
SELECT 
  cast(`datetime` AS DATE) AS `date`, 
  ROUND(SUM(`total`), 2) AS `revenue`
FROM `transactions`
GROUP BY `date`
ORDER BY `revenue` DESC
LIMIT 10;
```

| date       | revenue  |
| ---------- | -------- |
| 2015-05-13 | 13930.35 |
| 2014-11-10 | 5468.38  |
| 2015-02-16 | 5192.17  |
| 2014-09-08 | 4820.93  |
| 2014-12-22 | 4119.22  |
| 2015-02-26 | 3987.62  |
| 2015-02-20 | 3976.90  |
| 2015-03-27 | 3968.16  |
| 2015-01-15 | 3898.39  |
| 2015-05-22 | 3828.47  |


Get the ranking of days with the biggest revenue, with corresponding permanences

```sql
SELECT 
  `permanences`.`asso_name` AS `permanence`,
  cast(`transactions`.`datetime` AS DATE) AS `date`, 
  ROUND(SUM(`transactions`.`total`), 2) AS `revenue`
FROM `transactions`
INNER JOIN `permanences`
ON cast(`transactions`.`datetime` AS DATE) = cast(`permanences`.`datetime` AS DATE)
WHERE cast(`permanences`.`datetime` AS TIME) = "18:00:00"
GROUP BY `date`
ORDER BY `revenue` DESC
LIMIT 10;
```

| permanence         | date       | revenue  |
| ------------------ | ---------- | -------- |
| ESTU PARKING       | 2015-05-13 | 13930.35 |
| Vieux CompiBitches | 2014-11-10 | 5468.38  |
| Picasso            | 2015-02-16 | 5192.17  |
|                    | 2014-09-08 | 4820.93  |
| Picemons           | 2014-12-22 | 4119.22  |
| Rugby UTC          | 2015-02-26 | 3987.62  |
| Picasso            | 2015-02-20 | 3976.90  |
| P15 du Turfu       | 2015-03-27 | 3968.16  |
|                    | 2015-01-15 | 3898.39  |
| SDF                | 2015-05-22 | 3828.47  |


Get the ranking of the most popular products

```sql
SELECT
  `transactions`.`product_id` AS product_id, 
  `products`.`name` AS name, 
  SUM(`transactions`.`quantity`) AS quantity
FROM `transactions`
INNER JOIN `products`
ON `transactions`.`product_id` = `products`.`product_id`
GROUP   BY  `product_id`
ORDER   BY `quantity` DESC
LIMIT 10;
```

| product_id | name             | quantity |
| ---------- | ---------------- | -------- |
| 458        | Delirium Tremens | 17073    |
| 457        | Cuvee des Trolls | 15733    |
| 466        | Tripel Karmeliet | 13333    |
| 85         | Cafe             | 12983    |
| 1395       | Peche Mel Bush   | 11016    |
| 1401       | Gauloise Rouge   | 9705     |
| 1397       | Duvel            | 7538     |
| 3565       | Jo Colina        | 7337     |
| 1394       | Carolus Triple   | 7129     |
| 1403       | Barbar Blonde    | 6531     |

Get the ranking of products generating the most revenue

```sql
SELECT  
  `transactions`.`product_id` AS product_id, 
  `products`.`name` AS name, 
  ROUND(SUM(`transactions`.`total`), 2) AS revenue
FROM `transactions`
INNER JOIN `products`
ON `transactions`.`product_id` = `products`.`product_id`
GROUP BY `product_id`
ORDER BY `revenue` DESC
LIMIT 10;
```

| product_id | name             | revenue  |
| ---------- | ---------------- | -------- |
| 458        | Delirium Tremens | 30788.73 |
| 457        | Cuvee des Trolls | 26616.97 |
| 466        | Tripel Karmeliet | 24024.30 |
| 1395       | Peche Mel Bush   | 18735.73 |
| 1401       | Gauloise Rouge   | 17984.45 |
| 1394       | Carolus Triple   | 12473.67 |
| 1397       | Duvel            | 12428.13 |
| 3796       | Biere            | 12266.40 |
| 1399       | Chimay Bleue     | 10938.63 |
| 1403       | Barbar Blonde    | 10457.24 |


Get the average attendance depending on the weather type

```sql
SELECT x.description, x.nb_buyers / x.nb_mea FROM (
  SELECT
    weathers.description,
    COUNT(DISTINCT buyer_id) as nb_buyers,
    COUNT(DISTINCT measurements.measurement_id) as nb_mea
  FROM weathers
  INNER JOIN measurements ON weathers.weather_id = measurements.weather_id
  INNER JOIN transactions ON measurements.measurement_id = transactions.measurement_id
  WHERE CAST(measurements.datetime AS TIME) BETWEEN '10:00:00' AND '22:00:00'
  GROUP BY weathers.weather_id
  HAVING nb_mea > 10
) as x
ORDER BY x.nb_buyers / x.nb_mea DESC
;
```

| description          | x.nb_buyers / x.nb_mea |
| -------------------- | ---------------------- |
| Moderate rain        | 79.9474                |
| Patchy light drizzle | 46.0000                |
| Light rain shower    | 30.6410                |
| Overcast             | 30.6383                |
| Light rain           | 29.2200                |
| Light drizzle        | 28.0000                |
| Cloudy               | 21.2449                |
| Patchy rain nearby   | 18.0165                |
| Partly Cloudy        | 11.6119                |
| Sunny                | 6.9391                 |


Get the ranking of most popular products depending of the weather type (Example for weather description "Sunny" : weather_id=113)

```sql
SELECT
  `transactions`.`product_id` AS product_id, 
  `products`.`name` AS name, 
  SUM(`transactions`.`quantity`) AS quantity
FROM `transactions`
INNER JOIN `products`
ON `transactions`.`product_id` = `products`.`product_id`
INNER JOIN `measurements` 
ON `transactions`.`measurement_id` = `measurements`.`measurement_id`
WHERE `measurements`.`weather_id` = 113
AND `products`.`price` > 0.10
GROUP   BY  `product_id`
ORDER   BY `quantity` DESC
LIMIT 10;
;
```
| product_id | name             | quantity |
| ---------- | ---------------- | -------- |
| 458        | Delirium Tremens | 6413     |
| 457        | Cuvee des Trolls | 5868     |
| 466        | Tripel Karmeliet | 5052     |
| 85         | Cafe             | 4371     |
| 1395       | Peche Mel Bush   | 3986     |
| 1401       | Gauloise Rouge   | 3810     |
| 1397       | Carolus Triple   | 2728     |
| 3565       | Duvel            | 2640     |
| 1394       | Ecocup           | 2464     |
| 1403       | Kwak             | 2308     |


## Query data

Get all Scotch Silly transactions grouped by buyer

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  `products`.`name` as `product_name`,
  (`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
INNER JOIN `products`
ON `products`.`product_id` = `transactions`.`product_id`
WHERE `products`.`name` = 'Scotch Silly'
GROUP BY `transactions`.`buyer_id`
ORDER BY `sum` DESC;
```

Get all Scotch Silly transactions grouped by buyer on the 05-07-2014

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  `products`.`name` as `product_name`,
  (`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
INNER JOIN `products`
ON `products`.`product_id` = `transactions`.`product_id`
WHERE
  `datetime` BETWEEN '2015-05-07 00:00:00' AND '2015-05-07 23:59:59'
  AND `products`.`name` = 'Scotch Silly'
GROUP BY `transactions`.`buyer_id`
ORDER BY `sum` DESC;
```

Get all transactions grouped by product on the 05-07-2014

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  `products`.`name` as `product_name`,
  (`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
INNER JOIN `products`
ON `products`.`product_id` = `transactions`.`product_id`
WHERE
  `datetime` BETWEEN '2015-05-07 00:00:00' AND '2015-05-07 23:59:59'
GROUP BY `transactions`.`product_id`
ORDER BY `sum` DESC;
```

Get all transactions grouped by buyer on the 05-07-2014

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  `products`.`name` as `product_name`,
  (`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
INNER JOIN `products`
ON `products`.`product_id` = `transactions`.`product_id`
WHERE
  `datetime` BETWEEN '2015-05-07 00:00:00' AND '2015-05-07 23:59:59'
GROUP BY `transactions`.`buyer_id`
ORDER BY `sum` DESC;
```


## People

Hugo

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(total), 2) AS `sum`,
  MIN(`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
WHERE
  `datetime` BETWEEN '2015-02-27 00:00:00' AND '2015-02-27 23:59:59'
GROUP BY `buyer_id`
HAVING `sum` = '18.85'
ORDER BY `sum` DESC;
```

| buyer_id | quantity | sum     | from                | to                  |
| -------- | -------- | ------  | ------------------  | ------------------- |
| 5163     | 5        | 18.85   | 2015-02-27 18:37:52 | 2015-02-27 19:18:54 |


Alexandre

```sql
SELECT
  `buyer_id`,
  SUM(`quantity`) AS `quantity`,
  ROUND(SUM(`total`), 2) AS `sum`,
  `products`.`name` as `product_name`,
  (`datetime`) AS `from`,
  MAX(`datetime`) AS `to`
FROM `transactions`
INNER JOIN `products`
ON `products`.`product_id` = `transactions`.`product_id`
WHERE
  `datetime` BETWEEN '2014-12-01 00:00:00' AND '2014-12-31 23:59:59'
  AND `buyer_id` = 5358
GROUP BY `transactions`.`product_id`
ORDER BY `sum` DESC;
```

| buyer_id | quantity | sum     | product_name              | from                | to                  |
| -------- | -------- | ------  | ------------------------- | ------------------- | ------------------- |
| 5358     | 1        | 0.70    | Coca                      | 2014-12-17 14:39:04 | 2014-12-17 14:39:04 |
| 5358     | 1        | 1.60    | menu des bogoss du volley | 2014-12-16 18:34:31 | 2014-12-16 18:34:34 |
| 5358     | 3        | 2.25    | Pain au chocolat          | 2014-12-05 11:05:29 | 2014-12-16 10:02:54 |
| 5358     | 1        | 0.50    | Kit Kat                   | 2014-12-15 16:10:23 | 2014-12-15 16:10:24 |
| 5358     | 1        | 1.00    | Quich                     | 2014-12-15 12:33:08 | 2014-12-15 12:33:04 |
| 5358     | 2        | 0.80    | Cafe                      | 2014-12-08 14:11:02 | 2014-12-12 13:40:14 |
| 5358     | 1        | 1.50    | Repas de noel du BDE      | 2014-12-12 12:03:47 | 2014-12-12 12:03:44 |
| 5358     | 1        | 0.70    | Pulco ma gueule !         | 2014-12-10 15:12:40 | 2014-12-10 15:12:44 |
| 5358     | 1        | 0.70    | Belin Monaco 55g          | 2014-12-09 18:45:28 | 2014-12-09 18:45:24 |
| 5358     | 1        | 1.60    | Menu du chef TribUt       | 2014-12-09 18:27:42 | 2014-12-09 18:27:44 |
| 5358     | 1        | 0.70    | Sprite                    | 2014-12-05 15:24:32 | 2014-12-05 15:24:34 |
| 5358     | 2        | 1.40    | Schweppes                 | 2014-12-04 14:44:26 | 2014-12-05 12:30:04 |
| 5358     | 2        | 1.84    | Menu Rugby                | 2014-12-05 11:56:02 | 2014-12-05 11:56:04 |
| 5358     | 4        | 6.76    | Triple Moine              | 2014-12-04 20:15:32 | 2014-12-04 21:23:14 |
| 5358     | 1        | 1.85    | Gauloise 10               | 2014-12-04 19:35:55 | 2014-12-04 19:35:54 |
| 5358     | 2        | 3.70    | Bush 10                   | 2014-12-04 19:14:05 | 2014-12-04 19:14:04 |
| 5358     | 1        | 0.70    | M&Ms                      | 2014-12-04 13:29:28 | 2014-12-04 13:29:24 |
