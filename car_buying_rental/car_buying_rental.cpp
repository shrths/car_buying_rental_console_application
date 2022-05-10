
#include <stdlib.h>
#include<Windows.h>
#include <iostream>
#include<string.h>
#include<cstring>
#include<conio.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}
sql::Driver* driver;
sql::Connection* con;
sql::PreparedStatement* pstmt;
sql::Statement* stmt;
sql::ResultSet* res;

void adminLogin();
void userLogin();
void userHome();
void adminHome();
void adduser();
void addCarRent();
void addCarBuy();
void rentDetails();
void buyDetails();
void buying();
void process(int,string,string,string);
void renting();
void rentingProcess(int, string, string, string);


int main()
{
	try {

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "shrth");

	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	con->setSchema("car_rental");
	fullscreen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t1.Admin\n\t\t\t\t\t\t\t\t\t\t\t\t\t2.User\n\t\t\t\t\t\t\t\t\t\t\t\t\t3.Exit\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tI am an :";
	int ch;
	cin >> ch;
	if (ch == 1) {
		adminLogin();
		adminHome();
	}
	else if (ch == 2) {
		userLogin();
		
	}
	else if (ch == 3) {
		exit(0);
	}
	else {
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tNot an Available choice...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
		main();
	}
}

void adminLogin() {
	string password;
	char ch;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << " \t\t\t\t\t\t\t\t\t\t\t\t\t      Admin Login" << endl;
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your password :-";
	ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (password == "admin") {
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
		adminLogin();
	}
}

void userLogin() {
	string password;
	bool flag = false;
	char ch;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << " \t\t\t\t\t\t\t\t\t\t\t\t\t      User Login" << endl;
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your password :-";
	ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	pstmt = con->prepareStatement("SELECT login_pass FROM login");
	res = pstmt->executeQuery();
	
	while (res->next()) {
		if (password == res->getString("login_pass")) {
			cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
			system("PAUSE");
			system("CLS");
			userHome();
			flag = true;
		}
		else continue;
	}
	if (flag == false)
	{
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
		system("PAUSE");
		system("CLS");
		userLogin();
	}

	delete pstmt;
	delete con;
	delete res;
}

void adminHome() {
	int choice;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t1)Add user";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t2)Add new car for rent";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t3)Add new car to buy";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t4)All cars details in rental";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t5)All cars details for buying";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t6)Logout";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t================================================";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter your choice:-";
	cin >> choice;
	switch (choice)
	{
	case 1: adduser();
			break;

	case 2: addCarRent();
			break;

	case 3: addCarBuy();
			break;

	case 4: rentDetails();
			break;

	case 5: buyDetails();
		    break;

	case 6: cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank you ";
			system("PAUSE");
			system("CLS");
			main();
			break;
	default:cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter a proper choice\n";
			system("PAUSE");
			system("CLS");
			adminHome();
	}
}

void userHome() {
	int ch;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tHOME PAGE";
	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t1) Buy A Car\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t2) Rent A Car\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t3) Neither";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tI Am Here to : ";
	cin >> ch;
	switch (ch) {
	case 1: buying();
			break;
	case 2: renting();
			break;
	case 3: system("PAUSE");
		system("CLS");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tOKAY BYE!!!!\n\n";
		system("PAUSE");
		system("CLS");
		break;
	default:cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter a proper choice\n";
		system("PAUSE");
		system("CLS");
		userHome();

	}
}
void adduser() {
	int id;
	string pass;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t       Adding user data" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter user ID:- ";
	cin >> id;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter user Password:- ";
	cin >> pass;
	pstmt = con->prepareStatement("INSERT INTO login VALUES(?,?)");
	pstmt->setInt(1, id);
	pstmt->setString(2, pass);
	pstmt->execute();
	cout << "inserted";
	delete pstmt;
	delete con;
	system("PAUSE");
	system("CLS");
	adminHome();
} 

void addCarRent() {
	system("PAUSE");
	system("CLS");
	string name, mileage, rent, fuel_type, availability, transmission, airbag;
	int seat,car_num;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t   Adding new car for rent" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Car Name:- ";
	cin >> name;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Number of Seats :- ";
	cin >> seat;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Mileage :- ";
	cin >> mileage;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Rent :- ";
	cin >> rent;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Fuel Type :-";
	cin >> fuel_type;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Availability:- ";
	cin >> availability;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Transmission Type:- ";
	cin >> transmission;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Is there a airbag in the car? :- ";
	cin >> airbag;
	
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t enter car number:- ";
	cin >> car_num;
	
	pstmt = con->prepareStatement("INSERT INTO cars_for_rent VALUES(?,?,?,?,?,?,?,?,?)");
	
	pstmt->setString(1, name);
	pstmt->setInt(2, seat);
	pstmt->setString(3, mileage);
	pstmt->setString(4, rent);
	pstmt->setString(5, fuel_type);
	pstmt->setString(6, availability);
	pstmt->setString(7, transmission);
	pstmt->setString(8, airbag);
	pstmt->setInt(9, car_num);
	pstmt->execute();
	cout << "added";
	delete pstmt;
	delete con;
	system("PAUSE");
	system("CLS");
	adminHome();
}

void addCarBuy() {
	system("PAUSE");
	system("CLS");
	string name, mileage, fuel_type, transmission, airbag;
	int seat,price,car_num;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t   Adding new car for rent" << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Car Name:- ";
	cin >> name;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Number of Seats :- ";
	cin >> seat;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Mileage :- ";
	cin >> mileage;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Fuel Type :-";
	cin >> fuel_type;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Is there a airbag in the car? :- ";
	cin >> airbag;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter Transmission Type:- ";
	cin >> transmission;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Enter onroad price of the car:- ";
	cin >> price;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t enter car number:- ";
	cin >> car_num;

	pstmt = con->prepareStatement("INSERT INTO cars_to_buy VALUES(?,?,?,?,?,?,?,?)");
	
	pstmt->setString(1, name);
	pstmt->setInt(2, seat);
	pstmt->setString(3, mileage);
	pstmt->setString(4, fuel_type);
	pstmt->setString(5, airbag);
	pstmt->setString(6, transmission);
	pstmt->setInt(7, price);
	pstmt->setInt(8, car_num);
	pstmt->execute();
	cout << "added";
	delete pstmt;
	delete con;
	system("PAUSE");
	system("CLS");
	adminHome();

}
void rentDetails() {
	int go;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tRenting Cars Details";
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	cout << "\t\t\t\t\t|  Car Name        |Number of Seats|    Mileage    |     Rent      |      Fuel Type      |  Availability  |  Transmission Type  |  Airbags  |" << endl;
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	pstmt = con->prepareStatement("SELECT * FROM cars_for_rent");
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\t\t\t\t\t| " << res->getString("name") << "  \t" << res->getInt("seats") << "  \t\t" << res->getString("mileage") << "  \t" << res->getString("rent") << "  \t" << res->getString("fuel_type") << "  \t\t" << res->getString("availability") << "  \t\t" << res->getString("transmission_type") << "  \t\t" << res->getString("airbags") << "  |" << endl;
	}
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress 1 to go back: ";
	cin >> go;
	if (go == 1) {
		system("PAUSE");
		system("CLS");
		adminHome();
	}
	else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Proper number to exit..." << endl;
		rentDetails();
	}
	delete res;
	delete pstmt;
	delete con;
}
void buyDetails() {
	int go;
	system("PAUSE");
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tRenting Cars Details";
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	cout << "\t\t\t\t\t|  Car Name        |Number of Seats|    Mileage    |      Fuel Type      |  Airbags |  Transmission Type  |             Price  |" << endl;
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	pstmt = con->prepareStatement("SELECT * FROM cars_to_buy");
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\t\t\t\t\t| " << res->getString("name") << "  \t" << res->getInt("seats") << "  \t\t" << res->getString("mileage") <<"  \t" << res->getString("fuel_type") << "  \t\t" << res->getString("air_bags") << "  \t\t" << res->getString("transmission_type") << "  \t\t" << res->getString("price") << "  |" << endl;
	}
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress 1 to go back: ";
	cin >> go;
	if (go == 1) {
		system("PAUSE");
		system("CLS");
		adminHome();
	}
	else {
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Proper number to exit..." << endl;
		rentDetails();
	}
	delete res;
	delete pstmt;
	delete con;
}



void buying() {
	int go, count = 1;
	string name, mail, addr,phone;
	system("PAUSE");
	system("CLS");

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;

	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tBuying Cars Details";
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	pstmt = con->prepareStatement("SELECT * FROM cars_to_buy");
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\n\t\t\t\t\t|\tCar Number\t|\t" << count;
		cout << "\n\t\t\t\t\t|\tCar Name\t|\t" << res->getString("name");
		cout << "\n\t\t\t\t\t|\tNumber of Seats\t|\t" << res->getString("seats");
		cout << "\n\t\t\t\t\t|\tMileage\t\t|\t\t" << res->getString("mileage");
		cout << "\n\t\t\t\t\t|\tFuel Type\t|\t" << res->getString("fuel_type");
		cout << "\n\t\t\t\t\t|\tAirbags\t\t|\t" << res->getString("air_bags");
		cout << "\n\t\t\t\t\t|\tTransmission\t|\t" << res->getString("transmission_type");
		cout << "\n\t\t\t\t\t|\tOnroad Price\t|\t" << res->getString("price");
		cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
		count++;
	}

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tPress 0 to go back or type the car number to select the car to buy: ";
	cin >> go;
	if (go == 0) {
		system("PAUSE");
		system("CLS");
		userHome();
	}
	else {
		cout << "\n\n\t\t\t\t\t|\t\tEnter your Details:- \n";
		cout << "\n\t\t\t\t\t|\t\tEnter your name : - ";
		cin >> name;
		cout << "\n\t\t\t\t\t|\t\tEnter your phone number: - ";
		cin >> phone;
		cout << "\n\t\t\t\t\t|\t\tEnter the email id: - ";
		cin >> mail;
		
		process(go,name,phone,mail);
	}

}
	
void process(int num,string names,string phones, string mails) {
	system("PAUSE");
	system("CLS");
	string nums= to_string(num);
	cout << "\n\n\n\n\n\t\t\t\t\t\t\t|==============================================================================================\n";
	cout << "\n\n\t\t\t\t\t\t\t|\t\tHello " << names << ":)\n\n\t\t\t\t\t\t\t|\t\tThank you for your interest in buying car from our show room\n";
	

	string sql = "SELECT * FROM cars_to_buy WHERE car_nums="+nums;
	pstmt = con->prepareStatement(sql);
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\n\n\t\t\t\t\t\t\t|\t\tYou can find the details of your Selected Car below\t\t\n\n";
		cout << "\t\t\t\t\t\t\t|==============================================================================================\n";
		cout << "\n\n\t\t\t\t\t\t\t|\t\tCar Name\t|\t" << res->getString("name");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tNumber of Seats\t|\t" << res->getString("seats");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tMileage\t\t|\t\t" << res->getString("mileage");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tFuel Type\t|\t" << res->getString("fuel_type");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tAirbags\t\t|\t" << res->getString("air_bags");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tTransmission\t|\t" << res->getString("transmission_type");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tOnroad Price\t|\t" << res->getString("price");
		cout << "\n\n\t\t\t\t\t\t\t|==============================================================================================\n\n\n";
	}
	cout << "\t\t\t\t\t\t\t| We will send a Email to your personal email id ( " << mails << " ) also one of our employee\n\t\t\t\t\t\t\t| will call to your number "<<phones<<" by the end of the day for confirmation\n\n";
	cout << "\t\t\t\t\t\t\t| you can come to our showroom when you get a call or email about the car's arrival\n\t\t\t\t\t\t\t| You can find the link to our showroom location below\n\n";
	cout << "\t\t\t\t\t\t\t| Address:\n\t\t\t\t\t\t\t| C4 block, Wing A, MS Ramaiah North City, Manayata Tech Park, Nagavara, Bengaluru, Karnataka 560045\n\n\t\t\t\t\t\t\t| Location:\n\t\t\t\t\t\t\t| https://goo.gl/maps/GDbzUqKKjWLeR1ZP7";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank You :)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter 0 to go to home page : ";
	int going;
	cin >> going;
	if (going == 0) {
		system("PAUSE");
		system("CLS");
		userHome();
	}
	else {
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter a proper choice\n";
		system("PAUSE");
		system("CLS");
		process(num, names, phones, mails);
	}
	

	delete res;
	delete pstmt;
	delete con;

	
}
void renting() {
	int go, count = 1;
	string name, date, addr, phone;
	system("PAUSE");
	system("CLS");

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Car Buying And Rental" << endl;

	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\tRenting Cars Details";
	cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
	pstmt = con->prepareStatement("SELECT * FROM cars_for_rent");
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\n\t\t\t\t\t|\tCar Number\t|\t" << count;
		cout << "\n\t\t\t\t\t|\tCar Name\t|\t" << res->getString("name");
		cout << "\n\t\t\t\t\t|\tNumber of Seats\t|\t" << res->getString("seats");
		cout << "\n\t\t\t\t\t|\tMileage\t\t|\t\t" << res->getString("mileage");
		cout << "\n\t\t\t\t\t|\tFuel Type\t|\t" << res->getString("fuel_type");
		cout << "\n\t\t\t\t\t|\tAirbags\t\t|\t" << res->getString("airbags");
		cout << "\n\t\t\t\t\t|\tTransmission\t|\t" << res->getString("transmission_type");
		cout << "\n\t\t\t\t\t|\tAvailability\t|\t" << res->getString("availability");
		cout << "\n\t\t\t\t\t|\tRENT\t\t|\t" << res->getString("rent");
		cout << "\n\t\t\t\t\t=============================================================================================================================================\n";
		count++;
	}
	

	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tPress 0 to go back or type the car number to select the car to buy: ";
	cin >> go;
	
	if (go == 0) {
		system("PAUSE");
		system("CLS");
		userHome();
	}
	else {
		
		cout << "\n\n\t\t\t\t\t|\t\tEnter your Details:- \n";
		cout << "\n\t\t\t\t\t|\t\tEnter your name : - ";
		cin >> name;
		cout << "\n\t\t\t\t\t|\t\tEnter your phone number: - ";
		cin >> phone;
		cout << "\n\t\t\t\t\t|\t\tEnter the day on which you need to rent your car :- ";
		cin >> date;

		rentingProcess(go, name, phone, date);
	}
}

void rentingProcess(int num, string names, string phones, string dates) {
	system("PAUSE");
	system("CLS");
	string nums = to_string(num);
	cout << "\n\n\n\n\n\t\t\t\t\t\t\t|==============================================================================================\n";
	cout << "\n\n\t\t\t\t\t\t\t|\t\tHello " << names << ":)\n\n\t\t\t\t\t\t\t|\t\tThank you for your interest in renting car from our show room\n\n\t\t\t\t\t\t\t|\t\tYOUR BOOKING IS CONFIRMED\n";


	string sqls = "SELECT * FROM cars_for_rent WHERE car_num="+nums;
	pstmt = con->prepareStatement(sqls);
	res = pstmt->executeQuery();
	while (res->next()) {
		cout << "\n\n\t\t\t\t\t\t\t|\t\tYou can find the details of your Selected Car below\t\t\n\n";
		cout << "\t\t\t\t\t\t\t|==============================================================================================\n";
		cout << "\n\n\t\t\t\t\t\t\t|\t\tCar Name\t|\t" << res->getString("name");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tNumber of Seats\t|\t" << res->getInt("seats");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tMileage\t\t|\t\t" << res->getString("mileage");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tFuel Type\t|\t" << res->getString("fuel_type");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tAirbags\t\t|\t" << res->getString("airbags");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tTransmission\t|\t" << res->getString("transmission_type");
		cout << "\n\n\t\t\t\t\t\t\t|\t\tOnroad Price\t|\t" << res->getString("rent");
		cout << "\n\n\t\t\t\t\t\t\t|==============================================================================================\n\n\n";
	}
	cout << "\t\t\t\t\t\t\t| We will send a SMS to your personal Phone number also one of our employee\n\t\t\t\t\t\t\t| will call to your number " << phones << " by the end of the day for confirmation of the booking\n\n";
	cout << "\t\t\t\t\t\t\t| you can come to our showroom on "<<dates<<" and provide the requirements given below and take your selected car\n\t\t\t\t\t\t\t| You can find the link to our showroom location below\n\n";
	cout << "\t\t\t\t\t\t\t| Requirements\n\t\t\t\t\t\t\t| 1) Your original Drivers License\n\t\t\t\t\t\t\t| 2) A Copy of your aadar card\n\t\t\t\t\t\t\t| 3) 2 Passport size Photos\n";
	cout << "\t\t\t\t\t\t\t| Also amount of 5000 should be paid in which your total rent will be deducted and rest will be returned on returning of our car\n\n";
	cout << "\t\t\t\t\t\t\t| Address:\n\t\t\t\t\t\t\t| C4 block, Wing A, MS Ramaiah North City, Manayata Tech Park, Nagavara, Bengaluru, Karnataka 560045\n\n\t\t\t\t\t\t\t| Location:\n\t\t\t\t\t\t\t| https://goo.gl/maps/GDbzUqKKjWLeR1ZP7";
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tThank You :)\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter 0 to go to home page : ";
	int going;
	cin >> going;
	if (going == 0) {
		system("PAUSE");
		system("CLS");
		userHome();
	}
	else {
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter a proper choice\n";
		system("PAUSE");
		system("CLS");
		rentingProcess(num, names, phones, dates);
	}


	delete res;
	delete pstmt;
	delete con;
}