-- MySQL dump 10.13  Distrib 5.7.11, for Linux (i686)
--
-- Host: localhost    Database: student
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
-- Table structure for table `major`
--

DROP TABLE IF EXISTS `major`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `major` (
  `name` char(255) NOT NULL,
  `collage` char(255) DEFAULT NULL,
  `comment` text,
  `address` char(255) DEFAULT 'qweasdzxc',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `major`
--

LOCK TABLES `major` WRITE;
/*!40000 ALTER TABLE `major` DISABLE KEYS */;
INSERT INTO `major` VALUES ('huaxue','caiiaoxueyuan',NULL,'qweasdzxc'),('信号与信息处理','za','','qweasdzxc'),('光学','za',NULL,'qweasdzxc'),('地理学','za','','qweasdzxc'),('应用数学','za','','qweasdzxc'),('建筑学','za','','qweasdzxc'),('物理',NULL,NULL,'qweasdzxc'),('生物学','za','','qweasdzxc'),('电子信息工程','za','','qweasdzxc'),('计算机','za','','qweasdzxc');
/*!40000 ALTER TABLE `major` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` char(255) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `class` char(16) DEFAULT NULL,
  `major` char(255) DEFAULT NULL,
  `math` float(5,1) DEFAULT NULL,
  `c` float(5,1) DEFAULT NULL,
  `chinese` float(5,1) DEFAULT NULL,
  `total` float(6,1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `major` (`major`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`major`) REFERENCES `major` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (2,'Bob',22,'M','1','地理学',29.0,45.6,76.0,150.6),(3,'Maline',18,'F','1','应用数学',68.7,96.8,76.0,241.5),(4,'Bree',18,'F','2','计算机',45.0,78.0,86.0,209.0),(5,'Susan',19,'F','2','建筑学',87.0,96.0,86.0,269.0),(6,'Peter',23,'M','2','信号与信息处理',98.0,95.0,86.0,279.0);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-05-13 15:26:22
