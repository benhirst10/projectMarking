-- MySQL dump 10.13  Distrib 5.6.12, for Win64 (x86_64)
--
-- Host: localhost    Database: projectpreferences
-- ------------------------------------------------------
-- Server version	5.6.12-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `markingsetup`
--

DROP TABLE IF EXISTS `markingsetup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `markingsetup` (
  `uid` varchar(200) NOT NULL DEFAULT '',
  `surname` varchar(200) DEFAULT NULL,
  `forenames` varchar(200) DEFAULT NULL,
  `candidate_number` varchar(200) DEFAULT NULL,
  `degreecode` varchar(200) DEFAULT NULL,
  `supervisor` varchar(200) DEFAULT NULL,
  `secondmarker` varchar(200) DEFAULT NULL,
  `project` varchar(200) DEFAULT NULL,
  `supervisorFullName` varchar(200) DEFAULT NULL,
  `secondmarkerFullName` varchar(200) DEFAULT NULL,
  `hide` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `markingsetup`
--

LOCK TABLES `markingsetup` WRITE;
/*!40000 ALTER TABLE `markingsetup` DISABLE KEYS */;
INSERT INTO `markingsetup` VALUES ('std1','Blogs','Joe','099999991','BSCOSCO','bmh2','dd',' Chess Computer Player.\n    ','Hirst Ben Mr','Duffy Deborah Mrs',''),('std2','Doe','John','099999992','BSCOWMJ','jlb','srh','A Simple Model Checker in Prolog','Benn Jennifer Mrs','Hirst Susan Ms',''),('std3','Challa','Mark','099999993','BSCOSCO/S','bmh2','bmh2','Visual Zoom over Software Application Code','Hirst Ben Mr','Hirst Ben Mr',''),('std4','Challiflour','Thomas','099999994','BECOSCG','srh','dd','Game of Hex','Hirst Susan Ms','Duffy Deborah Mrs','');
/*!40000 ALTER TABLE `markingsetup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `projectpreferences`
--

DROP TABLE IF EXISTS `projectpreferences`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `projectpreferences` (
  `uid` varchar(200) NOT NULL DEFAULT '',
  `pref` int(11) NOT NULL DEFAULT '0',
  `project` longtext,
  PRIMARY KEY (`uid`,`pref`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `projectpreferences`
--

LOCK TABLES `projectpreferences` WRITE;
/*!40000 ALTER TABLE `projectpreferences` DISABLE KEYS */;
INSERT INTO `projectpreferences` VALUES ('std1',1,'4dfd06b842815491b953d2c2d5f673c3'),('std1',2,'ab220ef4498aff1e5a7b8f39c9be664b'),('std1',3,'project-9'),('std1',4,'4dfd06b842815491b953d2c2d5f673c3');
/*!40000 ALTER TABLE `projectpreferences` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-09-26  9:35:19
