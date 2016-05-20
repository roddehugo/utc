SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

CREATE DATABASE IF NOT EXISTS `nf17` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `nf17`;

CREATE TABLE IF NOT EXISTS `audimat` (
  `semaine` int(11) NOT NULL DEFAULT '0',
  `creneau_id` int(11) NOT NULL,
  `nb_spectateur` int(11) DEFAULT NULL,
  PRIMARY KEY (`semaine`,`creneau_id`),
  KEY `creneau_id` (`creneau_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `audimat` (`semaine`, `creneau_id`, `nb_spectateur`) VALUES
(1, 11, 0),
(1, 12, 0),
(1, 13, 0),
(1, 15, 0),
(1, 16, 0),
(2, 13, 0),
(2, 15, 0),
(2, 16, 0),
(3, 13, 0),
(3, 15, 0),
(3, 16, 0),
(4, 13, 0),
(4, 15, 0),
(4, 16, 0),
(5, 13, 0),
(5, 15, 0),
(5, 16, 0),
(6, 13, 0),
(6, 15, 0),
(6, 16, 0),
(7, 13, 0),
(7, 15, 0),
(7, 16, 0),
(8, 13, 0),
(8, 15, 0),
(8, 16, 0),
(9, 13, 0),
(9, 15, 0),
(9, 16, 0),
(10, 13, 0),
(10, 15, 0),
(10, 16, 0),
(11, 13, 0),
(11, 15, 0),
(11, 16, 0),
(12, 13, 0),
(12, 15, 0),
(12, 16, 0),
(13, 13, 0),
(13, 15, 0),
(13, 16, 0),
(14, 13, 0),
(14, 15, 0),
(14, 16, 0),
(15, 13, 0),
(15, 15, 0),
(15, 16, 0),
(16, 13, 0),
(16, 15, 0),
(16, 16, 0),
(17, 13, 0),
(17, 15, 0),
(17, 16, 0),
(18, 13, 0),
(18, 15, 0),
(18, 16, 0),
(19, 13, 0),
(19, 15, 0),
(19, 16, 0),
(20, 13, 0),
(20, 15, 0),
(20, 16, 0),
(21, 13, 0),
(21, 15, 0),
(21, 16, 0),
(22, 13, 0),
(22, 15, 0),
(22, 16, 0),
(23, 13, 0),
(23, 15, 0),
(23, 16, 0),
(24, 13, 0),
(24, 15, 0),
(24, 16, 0),
(25, 13, 0),
(25, 15, 0),
(25, 16, 0),
(26, 13, 0),
(26, 15, 0),
(26, 16, 0),
(27, 13, 0),
(27, 15, 0),
(27, 16, 0),
(28, 13, 0),
(28, 15, 0),
(28, 16, 0),
(29, 13, 0),
(29, 15, 0),
(29, 16, 0),
(30, 13, 0),
(30, 15, 0),
(30, 16, 0),
(31, 13, 0),
(31, 15, 0),
(31, 16, 0),
(32, 13, 0),
(32, 15, 0),
(32, 16, 0),
(33, 13, 0),
(33, 15, 0),
(33, 16, 0),
(34, 13, 0),
(34, 15, 0),
(34, 16, 0),
(35, 13, 0),
(35, 15, 0),
(35, 16, 0),
(36, 13, 0),
(36, 15, 0),
(36, 16, 0),
(37, 13, 0),
(37, 15, 0),
(37, 16, 0),
(38, 13, 0),
(38, 15, 0),
(38, 16, 0),
(39, 13, 0),
(39, 15, 0),
(39, 16, 0),
(40, 13, 0),
(40, 15, 0),
(40, 16, 0),
(41, 13, 0),
(41, 15, 0),
(41, 16, 0),
(42, 13, 0),
(42, 15, 0),
(42, 16, 0),
(43, 13, 0),
(43, 15, 0),
(43, 16, 0),
(44, 13, 0),
(44, 15, 0),
(44, 16, 0),
(45, 13, 0),
(45, 15, 0),
(45, 16, 0),
(46, 13, 0),
(46, 15, 0),
(46, 16, 0),
(47, 13, 0),
(47, 15, 0),
(47, 16, 0),
(48, 13, 0),
(48, 15, 0),
(48, 16, 0),
(49, 13, 0),
(49, 15, 0),
(49, 16, 0),
(50, 13, 0),
(50, 15, 0),
(50, 16, 0),
(51, 13, 0),
(51, 15, 0),
(51, 16, 0),
(52, 13, 0),
(52, 15, 0),
(52, 16, 0),
(53, 13, 0),
(53, 15, 0),
(53, 16, 0);

CREATE TABLE IF NOT EXISTS `chaine` (
  `nom_chaine` varchar(255) NOT NULL,
  `heure_debut` time NOT NULL,
  `heure_fin` time NOT NULL,
  `active` tinyint(1) DEFAULT NULL,
  `nom_dir` varchar(255) NOT NULL,
  `siege_id` int(11) NOT NULL,
  PRIMARY KEY (`nom_chaine`),
  KEY `nom_dir` (`nom_dir`),
  KEY `siege_id` (`siege_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `chaine` (`nom_chaine`, `heure_debut`, `heure_fin`, `active`, `nom_dir`, `siege_id`) VALUES
('Best', '00:00:00', '23:00:00', 1, 'Hugo', 1),
('M5', '06:00:00', '23:00:00', 1, 'Hugo', 1),
('TF5', '01:00:00', '23:00:00', 1, 'Hugo', 1),
('TF6', '11:00:00', '21:00:00', 1, 'Hugo', 1),
('TR7', '00:00:00', '23:00:00', 1, 'Hugo', 1),
('W9', '02:30:00', '23:45:00', 1, 'Hugo', 1);

CREATE TABLE IF NOT EXISTS `creneau` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `jour` enum('lundi','mardi','mercredi','jeudi','vendredi','samedi','dimanche') DEFAULT NULL,
  `heure_debut` time NOT NULL,
  `heure_fin` time NOT NULL,
  `grille_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `grille_id` (`grille_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=17 ;

INSERT INTO `creneau` (`id`, `jour`, `heure_debut`, `heure_fin`, `grille_id`) VALUES
(11, 'lundi', '00:00:00', '04:00:00', 1),
(12, 'lundi', '04:00:00', '06:00:00', 1),
(13, 'mardi', '10:00:00', '16:00:00', 1),
(14, 'mercredi', '10:00:00', '16:00:00', 1),
(15, 'jeudi', '10:00:00', '16:00:00', 1),
(16, 'lundi', '06:00:00', '10:00:00', 3);

CREATE TABLE IF NOT EXISTS `directeur_programme` (
  `nom_dir` varchar(255) NOT NULL,
  `date_embauche` date NOT NULL,
  PRIMARY KEY (`nom_dir`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `directeur_programme` (`nom_dir`, `date_embauche`) VALUES
('Hugo', '2013-05-09'),
('M2', '2013-05-28');

CREATE TABLE IF NOT EXISTS `documentaire` (
  `nom_docu` varchar(255) NOT NULL,
  `theme` varchar(255) NOT NULL,
  `id_realisateur` int(11) NOT NULL,
  `id_animateur` int(11) NOT NULL,
  `nom_studio` varchar(255) NOT NULL,
  `langue` varchar(255) NOT NULL DEFAULT '',
  `nom_pays` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`nom_docu`),
  KEY `theme` (`theme`),
  KEY `nom_studio` (`nom_studio`),
  KEY `id_realisateur` (`id_realisateur`),
  KEY `id_animateur` (`id_animateur`),
  KEY `langue` (`langue`),
  KEY `nom_pays` (`nom_pays`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `documentaire_creneau` (
  `docu` varchar(255) NOT NULL DEFAULT '',
  `creneau` int(11) NOT NULL,
  PRIMARY KEY (`docu`,`creneau`),
  KEY `creneau` (`creneau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `film` (
  `nom_film` varchar(255) NOT NULL,
  `annee_sortie` year(4) NOT NULL,
  `id_realisateur` int(11) NOT NULL,
  `nom_studio` varchar(255) NOT NULL,
  `nom_pays` varchar(255) NOT NULL DEFAULT '',
  `langue` varchar(255) NOT NULL,
  PRIMARY KEY (`nom_film`),
  KEY `nom_studio` (`nom_studio`),
  KEY `id_realisateur` (`id_realisateur`),
  KEY `langue` (`langue`),
  KEY `nom_pays` (`nom_pays`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `film` (`nom_film`, `annee_sortie`, `id_realisateur`, `nom_studio`, `nom_pays`, `langue`) VALUES
('Star Wars', 1993, 1, 'Lucas Film', 'France', 'VF');

CREATE TABLE IF NOT EXISTS `film_creneau` (
  `film` varchar(255) NOT NULL DEFAULT '',
  `creneau` int(11) NOT NULL,
  `semaine` int(11) NOT NULL,
  PRIMARY KEY (`film`,`creneau`,`semaine`),
  KEY `creneau` (`creneau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `film_creneau` (`film`, `creneau`, `semaine`) VALUES
('Star Wars', 11, 1),
('Star Wars', 14, 2),
('Star Wars', 16, 4);

CREATE TABLE IF NOT EXISTS `grille_programme` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom_chaine` varchar(255) DEFAULT NULL,
  `annee` year(4) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `nom_chaine` (`nom_chaine`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

INSERT INTO `grille_programme` (`id`, `nom_chaine`, `annee`) VALUES
(1, 'Best', 2013),
(2, 'TF5', 2013),
(3, 'M5', 2013),
(4, 'TR7', 2013);

CREATE TABLE IF NOT EXISTS `journal` (
  `nom_journal` varchar(255) NOT NULL,
  `id_animateur` int(11) NOT NULL,
  `langue` varchar(255) NOT NULL DEFAULT '',
  `nom_pays` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`nom_journal`),
  KEY `id_animateur` (`id_animateur`),
  KEY `langue` (`langue`),
  KEY `nom_pays` (`nom_pays`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `journal_creneau` (
  `journal` varchar(255) NOT NULL DEFAULT '',
  `creneau` int(11) NOT NULL,
  PRIMARY KEY (`journal`,`creneau`),
  KEY `creneau` (`creneau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `moyen_diffusion` (
  `genre` varchar(255) NOT NULL,
  PRIMARY KEY (`genre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `moyen_diffusion` (`genre`) VALUES
('Satellite'),
('Satellite HD');

CREATE TABLE IF NOT EXISTS `participe` (
  `personne_id` int(11) NOT NULL,
  `nom_emission` varchar(255) NOT NULL,
  `type_personne` enum('film','serie','journal') NOT NULL,
  PRIMARY KEY (`personne_id`,`nom_emission`),
  KEY `nom_emission` (`nom_emission`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `pays` (
  `nom_pays` varchar(45) NOT NULL DEFAULT '',
  PRIMARY KEY (`nom_pays`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `pays` (`nom_pays`) VALUES
('Afghanistan'),
('Afrique du Sud'),
('Albanie'),
('Algérie'),
('Allemagne'),
('Andorre'),
('Angola'),
('Anguilla'),
('Antarctique'),
('Antigua-et-Barbuda'),
('Antilles Néerlandaises'),
('Arabie Saoudite'),
('Argentine'),
('Arménie'),
('Aruba'),
('Australie'),
('Autriche'),
('Azerbaïdjan'),
('Bahamas'),
('Bahreïn'),
('Bangladesh'),
('Barbade'),
('Bélarus'),
('Belgique'),
('Belize'),
('Bénin'),
('Bermudes'),
('Bhoutan'),
('Bolivie'),
('Bosnie-Herzégovine'),
('Botswana'),
('Brésil'),
('Brunéi Darussalam'),
('Bulgarie'),
('Burkina Faso'),
('Burundi'),
('Cambodge'),
('Cameroun'),
('Canada'),
('Cap-vert'),
('Chili'),
('Chine'),
('Chypre'),
('Colombie'),
('Comores'),
('Costa Rica'),
('Côte d''Ivoire'),
('Croatie'),
('Cuba'),
('Danemark'),
('Djibouti'),
('Dominique'),
('Égypte'),
('El Salvador'),
('Émirats Arabes Unis'),
('Équateur'),
('Érythrée'),
('Espagne'),
('Estonie'),
('États Fédérés de Micronésie'),
('États-Unis'),
('Éthiopie'),
('Fédération de Russie'),
('Fidji'),
('Finlande'),
('France'),
('Gabon'),
('Gambie'),
('Géorgie'),
('Géorgie du Sud et les Îles Sandwich du Sud'),
('Ghana'),
('Gibraltar'),
('Grèce'),
('Grenade'),
('Groenland'),
('Guadeloupe'),
('Guam'),
('Guatemala'),
('Guinée'),
('Guinée Équatoriale'),
('Guinée-Bissau'),
('Guyana'),
('Guyane Française'),
('Haïti'),
('Honduras'),
('Hong-Kong'),
('Hongrie'),
('Île Bouvet'),
('Île Christmas'),
('Île de Man'),
('Île Norfolk'),
('Îles (malvinas) Falkland'),
('Îles Åland'),
('Îles Caïmanes'),
('Îles Cocos (Keeling)'),
('Îles Cook'),
('Îles Féroé'),
('Îles Heard et Mcdonald'),
('Îles Mariannes du Nord'),
('Îles Marshall'),
('Îles Mineures Éloignées des États-Unis'),
('Îles Salomon'),
('Îles Turks et Caïques'),
('Îles Vierges Britanniques'),
('Îles Vierges des États-Unis'),
('Inde'),
('Indonésie'),
('Iraq'),
('Irlande'),
('Islande'),
('Israël'),
('Italie'),
('Jamahiriya Arabe Libyenne'),
('Jamaïque'),
('Japon'),
('Jordanie'),
('Kazakhstan'),
('Kenya'),
('Kirghizistan'),
('Kiribati'),
('Koweït'),
('L''ex-République Yougoslave de Macédoine'),
('Lesotho'),
('Lettonie'),
('Liban'),
('Libéria'),
('Liechtenstein'),
('Lituanie'),
('Luxembourg'),
('Macao'),
('Madagascar'),
('Malaisie'),
('Malawi'),
('Maldives'),
('Mali'),
('Malte'),
('Maroc'),
('Martinique'),
('Maurice'),
('Mauritanie'),
('Mayotte'),
('Mexique'),
('Monaco'),
('Mongolie'),
('Montserrat'),
('Mozambique'),
('Myanmar'),
('Namibie'),
('Nauru'),
('Népal'),
('Nicaragua'),
('Niger'),
('Nigéria'),
('Niué'),
('Norvège'),
('Nouvelle-Calédonie'),
('Nouvelle-Zélande'),
('Oman'),
('Ouganda'),
('Ouzbékistan'),
('Pakistan'),
('Palaos'),
('Panama'),
('Papouasie-Nouvelle-Guinée'),
('Paraguay'),
('Pays-Bas'),
('Pérou'),
('Philippines'),
('Pitcairn'),
('Pologne'),
('Polynésie Française'),
('Porto Rico'),
('Portugal'),
('Qatar'),
('République Arabe Syrienne'),
('République Centrafricaine'),
('République de Corée'),
('République de Moldova'),
('République Démocratique du Congo'),
('République Démocratique Populaire Lao'),
('République Dominicaine'),
('République du Congo'),
('République Islamique d''Iran'),
('République Populaire Démocratique de Corée'),
('République Tchèque'),
('République-Unie de Tanzanie'),
('Réunion'),
('Roumanie'),
('Royaume-Uni'),
('Rwanda'),
('Sahara Occidental'),
('Saint-Kitts-et-Nevis'),
('Saint-Marin'),
('Saint-Pierre-et-Miquelon'),
('Saint-Siège (état de la Cité du Vatican)'),
('Saint-Vincent-et-les Grenadines'),
('Sainte-Hélène'),
('Sainte-Lucie'),
('Samoa'),
('Samoa Américaines'),
('Sao Tomé-et-Principe'),
('Sénégal'),
('Serbie-et-Monténégro'),
('Seychelles'),
('Sierra Leone'),
('Singapour'),
('Slovaquie'),
('Slovénie'),
('Somalie'),
('Soudan'),
('Sri Lanka'),
('Suède'),
('Suisse'),
('Suriname'),
('Svalbard etÎle Jan Mayen'),
('Swaziland'),
('Tadjikistan'),
('Taïwan'),
('Tchad'),
('Terres Australes Françaises'),
('Territoire Britannique de l''Océan Indien'),
('Territoire Palestinien Occupé'),
('Thaïlande'),
('Timor-Leste'),
('Togo'),
('Tokelau'),
('Tonga'),
('Trinité-et-Tobago'),
('Tunisie'),
('Turkménistan'),
('Turquie'),
('Tuvalu'),
('Ukraine'),
('Uruguay'),
('Vanuatu'),
('Venezuela'),
('Viet Nam'),
('Wallis et Futuna'),
('Yémen'),
('Zambie'),
('Zimbabwe');

CREATE TABLE IF NOT EXISTS `personne` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `nationalite` varchar(255) DEFAULT NULL,
  `telephone` varchar(14) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

INSERT INTO `personne` (`id`, `nom`, `prenom`, `nationalite`, `telephone`) VALUES
(1, 'Lucas', 'Georges', 'Etats-Unis', NULL),
(2, 'Disney', 'Walt', 'Etats-Unis', NULL),
(3, 'Poivre d''Arvor', 'Patrick', 'France', NULL),
(4, 'Bartès', 'Yan', 'France', NULL),
(5, 'Brimbo', 'Arthur', 'France', NULL),
(6, 'Voix', 'La Petite', 'France', NULL);

CREATE TABLE IF NOT EXISTS `populaire_emmission` (
  `type_public` varchar(255) NOT NULL,
  `nom_emission` varchar(255) NOT NULL,
  PRIMARY KEY (`nom_emission`,`type_public`),
  KEY `type_public` (`type_public`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `populaire_personne` (
  `type_public` varchar(255) NOT NULL,
  `personne_id` int(11) NOT NULL,
  `type_personne` enum('acteur','animateur') NOT NULL,
  PRIMARY KEY (`personne_id`,`type_public`,`type_personne`),
  KEY `type_public` (`type_public`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `public` (
  `type_public` varchar(255) NOT NULL,
  PRIMARY KEY (`type_public`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `public` (`type_public`) VALUES
('Adolescents'),
('Bébés'),
('Enfants'),
('Etudiants'),
('Femmes'),
('Grands-Parents'),
('Hommes'),
('Jeunes adultes'),
('Parents'),
('Personnes âgées'),
('Retraités');

CREATE TABLE IF NOT EXISTS `serie` (
  `nom_serie` varchar(255) NOT NULL,
  `genre` varchar(255) NOT NULL,
  `nom_studio` varchar(255) NOT NULL,
  `nom_pays` varchar(255) NOT NULL DEFAULT '',
  `langue` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`nom_serie`),
  KEY `genre` (`genre`),
  KEY `nom_studio` (`nom_studio`),
  KEY `nom_pays` (`nom_pays`),
  KEY `langue` (`langue`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `serie_creneau` (
  `serie` varchar(255) NOT NULL DEFAULT '',
  `creneau` int(11) NOT NULL,
  PRIMARY KEY (`serie`,`creneau`),
  KEY `creneau` (`creneau`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `siege_social` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `rue` varchar(255) NOT NULL,
  `ville` varchar(255) NOT NULL,
  `code_postal` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=2 ;

INSERT INTO `siege_social` (`id`, `rue`, `ville`, `code_postal`) VALUES
(1, '12 bis chemin de Moulon', 'Gif sur Yvette', 91190);

CREATE TABLE IF NOT EXISTS `studio` (
  `nom_studio` varchar(255) NOT NULL,
  PRIMARY KEY (`nom_studio`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `studio` (`nom_studio`) VALUES
('Disney'),
('France TV'),
('Hollywood'),
('Lucas Film');

CREATE TABLE IF NOT EXISTS `theme` (
  `nom_theme` varchar(255) NOT NULL,
  `type_theme` enum('documentaire','serie') NOT NULL,
  PRIMARY KEY (`nom_theme`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `theme` (`nom_theme`, `type_theme`) VALUES
('Action', 'serie'),
('Amour', 'serie'),
('Animaux', 'documentaire'),
('Fiction', 'serie'),
('Humour', 'serie'),
('Nature', 'documentaire'),
('Policier', 'serie'),
('Reportage', 'documentaire');

CREATE TABLE IF NOT EXISTS `utilise` (
  `nom_chaine` varchar(255) NOT NULL DEFAULT '',
  `genre` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`nom_chaine`,`genre`),
  KEY `genre` (`genre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `utilise` (`nom_chaine`, `genre`) VALUES
('TR7', 'Satellite'),
('TR7', 'Satellite HD');

CREATE TABLE IF NOT EXISTS `version` (
  `langue` varchar(255) NOT NULL,
  PRIMARY KEY (`langue`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `version` (`langue`) VALUES
('VF'),
('VO'),
('VOSTFR');

CREATE TABLE IF NOT EXISTS `vise` (
  `type_public` varchar(255) NOT NULL,
  `nom_emission` varchar(255) NOT NULL,
  PRIMARY KEY (`nom_emission`,`type_public`),
  KEY `type_public` (`type_public`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


ALTER TABLE `audimat`
  ADD CONSTRAINT `audimat_ibfk_1` FOREIGN KEY (`creneau_id`) REFERENCES `creneau` (`id`);

ALTER TABLE `chaine`
  ADD CONSTRAINT `chaine_ibfk_1` FOREIGN KEY (`nom_dir`) REFERENCES `directeur_programme` (`nom_dir`),
  ADD CONSTRAINT `chaine_ibfk_2` FOREIGN KEY (`siege_id`) REFERENCES `siege_social` (`id`);

ALTER TABLE `creneau`
  ADD CONSTRAINT `creneau_ibfk_1` FOREIGN KEY (`grille_id`) REFERENCES `grille_programme` (`id`);

ALTER TABLE `documentaire`
  ADD CONSTRAINT `documentaire_ibfk_2` FOREIGN KEY (`theme`) REFERENCES `theme` (`nom_theme`),
  ADD CONSTRAINT `documentaire_ibfk_3` FOREIGN KEY (`nom_studio`) REFERENCES `studio` (`nom_studio`),
  ADD CONSTRAINT `documentaire_ibfk_4` FOREIGN KEY (`id_realisateur`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `documentaire_ibfk_5` FOREIGN KEY (`id_animateur`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `documentaire_ibfk_7` FOREIGN KEY (`langue`) REFERENCES `version` (`langue`),
  ADD CONSTRAINT `documentaire_ibfk_8` FOREIGN KEY (`nom_pays`) REFERENCES `pays` (`nom_pays`);

ALTER TABLE `documentaire_creneau`
  ADD CONSTRAINT `documentaire_creneau_ibfk_2` FOREIGN KEY (`creneau`) REFERENCES `creneau` (`id`),
  ADD CONSTRAINT `documentaire_creneau_ibfk_1` FOREIGN KEY (`docu`) REFERENCES `documentaire` (`nom_docu`);

ALTER TABLE `film`
  ADD CONSTRAINT `film_ibfk_2` FOREIGN KEY (`nom_studio`) REFERENCES `studio` (`nom_studio`),
  ADD CONSTRAINT `film_ibfk_3` FOREIGN KEY (`id_realisateur`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `film_ibfk_5` FOREIGN KEY (`nom_pays`) REFERENCES `pays` (`nom_pays`),
  ADD CONSTRAINT `film_ibfk_6` FOREIGN KEY (`langue`) REFERENCES `version` (`langue`);

ALTER TABLE `film_creneau`
  ADD CONSTRAINT `film_creneau_ibfk_2` FOREIGN KEY (`creneau`) REFERENCES `creneau` (`id`),
  ADD CONSTRAINT `film_creneau_ibfk_1` FOREIGN KEY (`film`) REFERENCES `film` (`nom_film`);

ALTER TABLE `grille_programme`
  ADD CONSTRAINT `grille_programme_ibfk_1` FOREIGN KEY (`nom_chaine`) REFERENCES `chaine` (`nom_chaine`);

ALTER TABLE `journal`
  ADD CONSTRAINT `journal_ibfk_2` FOREIGN KEY (`id_animateur`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `journal_ibfk_3` FOREIGN KEY (`langue`) REFERENCES `version` (`langue`),
  ADD CONSTRAINT `journal_ibfk_4` FOREIGN KEY (`nom_pays`) REFERENCES `pays` (`nom_pays`);

ALTER TABLE `journal_creneau`
  ADD CONSTRAINT `journal_creneau_ibfk_2` FOREIGN KEY (`creneau`) REFERENCES `creneau` (`id`),
  ADD CONSTRAINT `journal_creneau_ibfk_1` FOREIGN KEY (`journal`) REFERENCES `journal` (`nom_journal`);

ALTER TABLE `participe`
  ADD CONSTRAINT `participe_ibfk_1` FOREIGN KEY (`personne_id`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `participe_ibfk_2` FOREIGN KEY (`nom_emission`) REFERENCES `emission` (`nom_emission`);

ALTER TABLE `populaire_emmission`
  ADD CONSTRAINT `populaire_emmission_ibfk_1` FOREIGN KEY (`nom_emission`) REFERENCES `emission` (`nom_emission`),
  ADD CONSTRAINT `populaire_emmission_ibfk_2` FOREIGN KEY (`type_public`) REFERENCES `public` (`type_public`);

ALTER TABLE `populaire_personne`
  ADD CONSTRAINT `populaire_personne_ibfk_1` FOREIGN KEY (`personne_id`) REFERENCES `personne` (`id`),
  ADD CONSTRAINT `populaire_personne_ibfk_2` FOREIGN KEY (`type_public`) REFERENCES `public` (`type_public`);

ALTER TABLE `serie`
  ADD CONSTRAINT `serie_ibfk_2` FOREIGN KEY (`genre`) REFERENCES `theme` (`nom_theme`),
  ADD CONSTRAINT `serie_ibfk_3` FOREIGN KEY (`nom_studio`) REFERENCES `studio` (`nom_studio`),
  ADD CONSTRAINT `serie_ibfk_4` FOREIGN KEY (`langue`) REFERENCES `version` (`langue`),
  ADD CONSTRAINT `serie_ibfk_6` FOREIGN KEY (`nom_pays`) REFERENCES `pays` (`nom_pays`);

ALTER TABLE `serie_creneau`
  ADD CONSTRAINT `serie_creneau_ibfk_2` FOREIGN KEY (`creneau`) REFERENCES `creneau` (`id`),
  ADD CONSTRAINT `serie_creneau_ibfk_1` FOREIGN KEY (`serie`) REFERENCES `serie` (`nom_serie`);

ALTER TABLE `utilise`
  ADD CONSTRAINT `utilise_ibfk_1` FOREIGN KEY (`nom_chaine`) REFERENCES `chaine` (`nom_chaine`),
  ADD CONSTRAINT `utilise_ibfk_2` FOREIGN KEY (`genre`) REFERENCES `moyen_diffusion` (`genre`);

ALTER TABLE `vise`
  ADD CONSTRAINT `vise_ibfk_1` FOREIGN KEY (`nom_emission`) REFERENCES `emission` (`nom_emission`),
  ADD CONSTRAINT `vise_ibfk_2` FOREIGN KEY (`type_public`) REFERENCES `public` (`type_public`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
