-- MySQL dump 10.13  Distrib 5.7.11, for Linux (i686)
--
-- Host: localhost    Database: order_system_lrh
-- ------------------------------------------------------
-- Server version	5.7.11-0ubuntu6

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
-- Table structure for table `c_comment`
--

DROP TABLE IF EXISTS `c_comment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `c_comment` (
  `sc_num` int(11) NOT NULL,
  `sc_com` char(80) NOT NULL,
  `cl_num` int(11) NOT NULL,
  `c_num` int(11) NOT NULL,
  PRIMARY KEY (`sc_num`),
  KEY `cl_num` (`cl_num`),
  KEY `c_num` (`c_num`),
  CONSTRAINT `c_comment_ibfk_1` FOREIGN KEY (`cl_num`) REFERENCES `client` (`cl_num`),
  CONSTRAINT `c_comment_ibfk_2` FOREIGN KEY (`c_num`) REFERENCES `courier` (`c_num`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `c_comment`
--

LOCK TABLES `c_comment` WRITE;
/*!40000 ALTER TABLE `c_comment` DISABLE KEYS */;
/*!40000 ALTER TABLE `c_comment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cancel`
--

DROP TABLE IF EXISTS `cancel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cancel` (
  `num` int(11) NOT NULL,
  `s_num` int(11) NOT NULL,
  PRIMARY KEY (`num`),
  KEY `s_num` (`s_num`),
  CONSTRAINT `cancel_ibfk_1` FOREIGN KEY (`s_num`) REFERENCES `shop` (`s_num`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cancel`
--

LOCK TABLES `cancel` WRITE;
/*!40000 ALTER TABLE `cancel` DISABLE KEYS */;
/*!40000 ALTER TABLE `cancel` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `client` (
  `cl_num` int(11) NOT NULL,
  `cl_name` char(50) NOT NULL,
  `cl_tel` char(11) NOT NULL,
  `cl_add` char(50) NOT NULL,
  `cl_pass` char(6) DEFAULT '111111',
  `cl_pass_pay` char(6) DEFAULT '123456',
  `cl_money` float DEFAULT '0',
  `cancel` int(11) DEFAULT '0',
  `state` int(11) DEFAULT '2',
  PRIMARY KEY (`cl_num`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
/*!40000 ALTER TABLE `client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `courier`
--

DROP TABLE IF EXISTS `courier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `courier` (
  `c_num` int(11) NOT NULL,
  `c_name` char(50) NOT NULL,
  `c_tel` char(11) NOT NULL,
  `c_pass` char(6) DEFAULT '333333',
  PRIMARY KEY (`c_num`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courier`
--

LOCK TABLES `courier` WRITE;
/*!40000 ALTER TABLE `courier` DISABLE KEYS */;
/*!40000 ALTER TABLE `courier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `dishes`
--

DROP TABLE IF EXISTS `dishes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `dishes` (
  `d_num` int(11) NOT NULL,
  `d_classname` char(50) NOT NULL,
  `d_name` char(50) NOT NULL,
  `d_price` float NOT NULL,
  `s_num` int(11) NOT NULL,
  PRIMARY KEY (`d_num`),
  KEY `s_num` (`s_num`),
  CONSTRAINT `dishes_ibfk_1` FOREIGN KEY (`s_num`) REFERENCES `shop` (`s_num`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `dishes`
--

LOCK TABLES `dishes` WRITE;
/*!40000 ALTER TABLE `dishes` DISABLE KEYS */;
INSERT INTO `dishes` VALUES (200100,'chao cai','xi hong shi ji dan',7,2001),(200101,' chao cai','mu er chao dan',8,2001);
/*!40000 ALTER TABLE `dishes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `indent`
--

DROP TABLE IF EXISTS `indent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `indent` (
  `num` int(11) NOT NULL,
  `name` char(100) NOT NULL,
  `price` float(6,2) NOT NULL,
  `cl_num` int(11) NOT NULL,
  `s_num` int(11) NOT NULL,
  `c_num` int(11) DEFAULT '0',
  `c_name` char(50) DEFAULT 'no',
  `c_tel` char(11) DEFAULT 'no',
  `state` int(11) NOT NULL,
  `Date` date NOT NULL,
  `Time` time NOT NULL,
  PRIMARY KEY (`num`),
  KEY `cl_num` (`cl_num`),
  KEY `s_num` (`s_num`),
  CONSTRAINT `indent_ibfk_1` FOREIGN KEY (`cl_num`) REFERENCES `client` (`cl_num`),
  CONSTRAINT `indent_ibfk_2` FOREIGN KEY (`s_num`) REFERENCES `shop` (`s_num`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `indent`
--

LOCK TABLES `indent` WRITE;
/*!40000 ALTER TABLE `indent` DISABLE KEYS */;
/*!40000 ALTER TABLE `indent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `s_comment`
--

DROP TABLE IF EXISTS `s_comment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `s_comment` (
  `sc_num` int(11) NOT NULL,
  `sc_com` char(80) NOT NULL,
  `cl_num` int(11) NOT NULL,
  `s_num` int(11) NOT NULL,
  PRIMARY KEY (`sc_num`),
  KEY `cl_num` (`cl_num`),
  KEY `s_num` (`s_num`),
  CONSTRAINT `s_comment_ibfk_1` FOREIGN KEY (`cl_num`) REFERENCES `client` (`cl_num`),
  CONSTRAINT `s_comment_ibfk_2` FOREIGN KEY (`s_num`) REFERENCES `shop` (`s_num`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `s_comment`
--

LOCK TABLES `s_comment` WRITE;
/*!40000 ALTER TABLE `s_comment` DISABLE KEYS */;
/*!40000 ALTER TABLE `s_comment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shop`
--

DROP TABLE IF EXISTS `shop`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `shop` (
  `s_num` int(11) NOT NULL,
  `s_name` char(50) NOT NULL,
  `s_tel` char(11) NOT NULL,
  `s_add` char(50) NOT NULL,
  `s_pass` char(6) DEFAULT '222222',
  `s_income` float DEFAULT '0',
  `policy` int(11) DEFAULT '1',
  `price_send` float DEFAULT '0',
  `discount` float DEFAULT '1',
  `full` float DEFAULT '0',
  `rece` float DEFAULT '0',
  PRIMARY KEY (`s_num`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shop`
--

LOCK TABLES `shop` WRITE;
/*!40000 ALTER TABLE `shop` DISABLE KEYS */;
INSERT INTO `shop` VALUES (2001,'qwe','12313133','gdfjlksjf','222222',0,1,0,1,0,0);
/*!40000 ALTER TABLE `shop` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-07-27 14:02:54
