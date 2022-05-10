-- MySQL dump 10.13  Distrib 8.0.29, for Win64 (x86_64)
--
-- Host: localhost    Database: car_rental
-- ------------------------------------------------------
-- Server version	8.0.29

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `cars_to_buy`
--

DROP TABLE IF EXISTS `cars_to_buy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cars_to_buy` (
  `name` varchar(45) NOT NULL,
  `seats` int NOT NULL,
  `mileage` varchar(45) NOT NULL,
  `fuel_type` varchar(45) NOT NULL,
  `air_bags` varchar(45) NOT NULL,
  `transmission_type` varchar(45) NOT NULL,
  `price` int NOT NULL,
  `car_nums` int NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`car_nums`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cars_to_buy`
--

LOCK TABLES `cars_to_buy` WRITE;
/*!40000 ALTER TABLE `cars_to_buy` DISABLE KEYS */;
INSERT INTO `cars_to_buy` VALUES ('Hyundai creta',5,'18 kmpl','Petrol','Yes','Automatic',1020000,1),('Maruti Baleno',5,'22 kmpl','Diesel','Yes','Manual',635000,2),('Hyundai santro',5,'20 kmpl','Petrol','No','Manual',486000,3),('Maruti Ertiga',7,'26.11 kmpl','Petrol','Yes','Manual',835000,4),('Mahindra XUV 300',5,'20 kmpl','Diesel','Yes','Automatic',945000,5),('Volkswagen Taigun',5,'19.2kmpl','Petrol','Yes','Manual',1140000,6),('Volkswagen POLO',5,'18.24 kmpl','Petrol','Yes','Automatic',724000,7),('Mahindra Thar',4,'15.2 kmpl','Petrol','Yes','Manual',1607000,8),('Mahindra Bolero',7,'16 kmpl','Diesel','Yes','Manual',933000,9),('Hyundai Alcazar',7,'20.4 kmpl','Diesel','Yes','Automatic',1634000,10),('Mahindra XUV-700',7,'16kmpl','Petrol','Yes','Automatic',2910000,11),('maruthi_omni',7,'21kmpl','Diesel','No','Manual',120000,12);
/*!40000 ALTER TABLE `cars_to_buy` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-10 13:57:43
