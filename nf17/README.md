# NF17 - Databases design

## Objective
This course objective is to teach students how to design relational and object-relational databases. In order to achieve this objective, the students will develop methodological skills for conceptual and logical modelling, as well as technological skills toward typical DBMS and toward usually used languages.

## Keywords
  * database
  * conceptual model
  * relational
  * SQL
  * object
  * transaction
  * web
  * dbms

## Architecture
<pre>
├── ajax                        ==> Contient les fichiers pour les ajax requests get/add
├── assets                      ==> Contient les css et images et js
│   ├── css
│   ├── ico
│   ├── img
│   └── js
├── classes                     ==> Contient les classes php
│   ├── cas.class.php
│   ├── curl.class.php
│   ├── db.class.php
│   └── session.class.php
├── elements                    ==> Contient les éléments de views et les formulaires d'ajout
├── index.php                   ==> l'index
├── 404.php                     ==> l'erreur 404 si requete directe sans passer par ajax depuis un add/get
├── nf17.sql				            ==> le dump sql
├── README.md
└── views                       ==> les vues et layouts
    ├── layout.phtml
    ├── login.phtml
    └── modal.phtml
</pre>

## Ajout de formulaire
	1. ajouter le lien dans la vue layouts.phtml avec la class ajax avec l'attribut html data-value="FooBar" en camelCase
	2. créer le formulaire d'insertion dans elements avec la syntaxe camelCase du data-value
	3. créer le script d'ajout dans la bdd dans ajax avec la syuntaxe camelcase addFooBar.php du data-value

	/!\ Il est conseillé de dupliquer et modifier un fichier déjà présent ;)