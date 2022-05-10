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
-- Table structure for table `cars_for_rent`
--

DROP TABLE IF EXISTS `cars_for_rent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cars_for_rent` (
  `name` varchar(45) NOT NULL,
  `seats` int NOT NULL,
  `mileage` varchar(45) NOT NULL,
  `rent` varchar(45) NOT NULL,
  `fuel_type` varchar(45) NOT NULL,
  `availability` varchar(45) NOT NULL,
  `transmission_type` varchar(45) NOT NULL,
  `airbags` varchar(45) NOT NULL,
  `car_num` int NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`car_num`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cars_for_rent`
--

LOCK TABLES `cars_for_rent` WRITE;
/*!40000 ALTER TABLE `cars_for_rent` DISABLE KEYS */;
INSERT INTO `cars_for_rent` VALUES ('Mahindra Thar',4,'15.2 kmpl','85 rs/hr','Petrol','Yes','Manual','Yes',1),('Hyundai Santro',5,'20 kmpl','80 rs/hr','Petrol','Yes','Manual','No',2),('Mahindra XUV 300',5,'20kmpl','81 rs/hr','Diesel','Yes','Automatic','Yes',3),('Volkswagen POLO',5,'18.24 kmpl','81 rs/hr','Petrol','Yes','Automatic','Yes',4),('Mahindra Baleno',5,'22 kmpl','83 rs/hr','Diesel','Yes','Manual','Yes',5),('Mahindra Bolaro',7,'16 kmpl','79 rs/hr','Diesel','Yes','Manual','Yes',6),('Hyundai Alcazar',7,'20.4 kmpl','83 rs/hr','Diesel','Yes','Automatic','Yes ',7),('Volkswagen Taigun',5,'19.2 kmpl','80 rs/hr','Petrol','Yes','Manual','Yes',8),('Maruti Ertiga',7,'26kmpl','81rs/hr','Diesel','Yes','Manual','Yes',9),('Hyundai Creta',5,'18 kmpl','82 rs/hr','Petrol','Yes','manual','Yes',10),('Mahindra XUV-700',7,'16kmpl','84rs/hr','Petrol','Yes','Automatic','Yes',11),('Maruti_swift',4,'20kmpl','79rs/hr','Diesel','Yes','Manual','Yes',12),('Maruthi_omni',7,'21kmpl','70rs/hr','Diesel','Yes','Manual','No',13);
/*!40000 ALTER TABLE `cars_for_rent` ENABLE KEYS */;
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
