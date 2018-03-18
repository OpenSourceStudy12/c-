-- MySQL dump 10.13  Distrib 5.7.11, for Linux (i686)
--
-- Host: localhost    Database: order_system
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
INSERT INTO `client` VALUES (1002,'3','123321','42523456','123321','123456',389,0,2),(1004,'4','4','4','111111','123456',100,0,2),(1005,'lrh','132981112','25534','111111','123321',114,0,2),(1006,'0','13298331913','345678','111111','123456',18,0,2);
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
INSERT INTO `courier` VALUES (3001,'1','13298331913','123321'),(3002,'lrh','13298331913','333333'),(3003,'5','5','333333'),(3004,'23','23','333333');
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
INSERT INTO `dishes` VALUES (200102,'13445','234',14,2001),(200104,'43565','543687',16,2001),(200105,'2143','34354',13,2001),(200106,'1234','576 5657',15,2001),(200200,'134354','454678',16,2002),(200700,'13224','324324',12,2007);
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
INSERT INTO `indent` VALUES (2,'234*1',4.76,1002,2001,0,'no name','no tel',-2,'2017-05-25','10:50:22'),(3,'sdgf*1',4.76,1002,2001,0,'no name','no tel',-2,'2017-05-25','11:36:38'),(4,'234*1 34354*1',40.00,1002,2001,3001,'1','13298331913',5,'2017-05-25','17:15:16'),(5,'454678*2',29.00,1002,2002,3001,'1','13298331913',5,'2017-05-25','17:16:09'),(6,'34354*1',26.00,1004,2001,3001,'1','13298331913',-2,'2017-05-25','17:17:39'),(7,'543687*1 576 5657*1',44.00,1005,2001,0,'no name','no tel',-2,'2017-05-25','17:22:25'),(8,'234*3 543687*2',82.00,1006,2001,0,'no name','no tel',0,'2017-05-25','17:26:40'),(9,'234*1 34354*2',53.00,1002,2001,0,'no name','no tel',0,'2017-05-25','20:03:09');
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
INSERT INTO `shop` VALUES (2001,'1','','1435676','321123',138,3,13,0.87,67,5),(2002,'2','2','2','222222',77,3,0,0.45,20,3),(2003,'lrh','13298331913','123578689','222222',0,2,0,0.12,40,4),(2004,'4','4','4','222222',0,1,0,1,0,0),(2005,'0','0','0','222222',0,1,0,1,0,0),(2006,'9','9','9','222222',0,1,0,1,0,0),(2007,'3','3','3','222222',0,1,0,1,0,0),(2008,'8','8','8','222222',0,1,0,1,0,0);
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

-- Dump completed on 2017-06-25 20:12:27
