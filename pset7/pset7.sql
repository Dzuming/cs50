-- MySQL dump 10.13  Distrib 5.5.43, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.43-0ubuntu0.14.04.1-log

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
-- Table structure for table `Portfolio`
--

DROP TABLE IF EXISTS `Portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Portfolio` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(12) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`),
  CONSTRAINT `shares_ibfk_1` FOREIGN KEY (`id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Portfolio`
--

LOCK TABLES `Portfolio` WRITE;
/*!40000 ALTER TABLE `Portfolio` DISABLE KEYS */;
INSERT INTO `Portfolio` VALUES (6,'AMZN',199),(6,'GOOG',12),(40,'AMZN',1),(40,'GOOG',1);
/*!40000 ALTER TABLE `Portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(11) NOT NULL,
  `transaction` varchar(4) COLLATE utf8_unicode_ci NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `symbol` varchar(6) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(11) NOT NULL,
  `price` decimal(65,4) NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (6,'SELL','2015-05-30 21:03:33','AMZN',456,429.2300),(6,'SELL','2015-05-30 21:06:38','AMZN',345,429.2300),(6,'SELL','2015-05-30 21:07:09','AMZN',1,429.2300),(6,'BUY','2015-05-30 21:09:09','GOOG',45,532.1100),(6,'BUY','2015-05-30 21:09:18','GOOG',53,532.1100),(6,'BUY','2015-05-30 21:32:29','AMZN',456,429.2300),(6,'BUY','2015-05-30 22:57:44','AMZN',456,430.9200),(6,'BUY','2015-05-30 22:57:54','FREE',56,0.0550),(40,'BUY','2015-05-30 22:59:07','AMZN',45,430.9200),(40,'BUY','2015-05-30 22:59:34','AMZN',3456,430.9200),(40,'BUY','2015-05-30 23:00:59','AMZN',543,430.9200),(40,'BUY','2015-05-30 23:09:40','AMZN',333333333,430.9200),(40,'BUY','2015-05-30 23:10:21','GOOG',1111111,533.9900),(40,'BUY','2015-05-30 23:12:01','AMZN',2147483647,430.9200),(40,'BUY','2015-05-30 23:13:08','GOOG',4,533.9900),(6,'BUY','2015-05-30 23:13:27','AMZN',333,430.9200),(40,'BUY','2015-05-30 23:48:33','AMZN',12,430.9200),(40,'BUY','2015-05-30 23:50:41','AMZN',1,430.9200),(40,'BUY','2015-05-30 23:51:40','AMZN',1,430.9200),(6,'BUY','2015-05-31 05:37:15','AMZN',123,430.9900),(6,'BUY','2015-05-31 05:45:20','AMZN',123,430.9900),(40,'BUY','2015-05-31 05:45:40','AMZN',1,430.9900),(40,'SELL','2015-05-31 05:46:30','AMZN',1,430.9900),(40,'BUY','2015-05-31 05:47:05','GOOG',1,539.1800),(40,'SELL','2015-05-31 05:47:41','GOOG',1,539.1800),(40,'BUY','2015-05-31 05:47:50','AMZN',1,430.9900),(40,'SELL','2015-05-31 05:47:57','AMZN',1,430.9900),(40,'BUY','2015-05-31 05:52:36','AMZN',1,430.9900),(40,'BUY','2015-05-31 05:55:23','GOOG',1,539.1800),(6,'BUY','2015-05-31 06:23:35','F',2,15.2600),(6,'BUY','2015-05-31 06:36:01','AMZN',43,430.9900),(6,'BUY','2015-05-31 06:36:16','AMZN',33,430.9900),(6,'BUY','2015-05-31 06:36:27','GOOG',12,539.1800),(6,'SELL','2015-05-31 06:46:07','F',2,15.2600);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=43 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'belindazeng','$1$50$oxJEDBo9KDStnrhtnSzir0',36383744.7614),(2,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',36383744.7614),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',36383744.7614),(4,'malan','$1$50$lJS9HiGK6sphej8c4bnbX.',36383744.7614),(5,'rob','$1$HA$l5llES7AEaz8ndmSo5Ig41',36383744.7614),(6,'skroob','$1$xn5CLT9Y$VjchsQpfFGSWWhrjcKQU9/',36383744.7614),(7,'zamyla','$1$50$uwfqB45ANW.9.6qaQ.DcF.',36383744.7614),(9,'daw','$1$6H6FFopO$/8iownJMq6bbrSS7maAKt0',36383744.7614),(10,'dd','$1$S01tWBkO$GXI1mPdZQYpApb.pKA0mO0',36383744.7614),(17,'d','$1$5BxZK4zU$2Ynib6Gsnvc3bvkws6KC11',36383744.7614),(24,'z','$1$wY/TGWeA$RknK3UEOLRUMjFzrie4dm/',36383744.7614),(25,'zx','$1$vdmrJJ2S$8fRxSJqCGicKY1EhygvzL0',36383744.7614),(26,'c','$1$WpBgJzuS$xjYxOsrWSJ34OsWCAPDXs1',36383744.7614),(28,'bj','$1$f9XZPo.i$GVCyHlu4f3dd2tEs4d3T71',36383744.7614),(30,'lo','$1$sEY19ceJ$r2G5RQNUGhADQogtWSwsb0',36383744.7614),(31,'v','$1$c34rVPCm$xov0x1hEnmVn0mN7Ssbyc0',36383744.7614),(32,'n','$1$C3JIHjS5$994sKzXxCpFvkPIvkCb9u/',36383744.7614),(35,'q','$1$TOsoRVYv$lNc01riRUcbpiFeManEjs1',36383744.7614),(36,'e','$1$adcuWPGC$48TFraSOIwt.DQDrLDNkR.',36383744.7614),(37,'y','$1$0IBLatpM$gRhKEw4LEZmwnNiclYmSf1',36383744.7614),(39,'cc','$1$Wym7KyPR$tGPUFSSDj87eZgqzzFb52/',36383744.7614),(40,'as','$1$/U4HbTxw$kTNL97zC4Z4M7Dnwdwapl0',10000.0000),(41,'33','$1$hLsxpmRk$lmgM/Y7C0zYBtElCEkyFn/',10000.0000),(42,'32','$1$eM6ulsTG$Zm.sltuy5DV7MoLwhChxN.',10000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-05-31  2:55:04
