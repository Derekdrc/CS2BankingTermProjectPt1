//Derek D'Arcy & Angela Ladd
//CS2 Term Project Pt 1
//Banking Management System
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif					//This is used for the sleep function

#include "Customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void start(vector<Customer>&);
int menu();
void createCustomer(vector<Customer>&);
void deleteCustomer(vector<Customer>&);
void updateCustomer(vector<Customer>&);
void deposit(vector<Customer>&);
void withdrawl(vector<Customer>&);
void viewCustomerInfo(vector<Customer>&);
void listCustomers(vector<Customer>&);
void sortAccountId(vector<Customer>&);
void sortName(vector<Customer>&);
void stop(vector<Customer>&);


int main() {
	vector<Customer> customers;
	start(customers);
	int choice = 0;
	while (choice != 8) {
		choice = menu();
		switch (choice) {
		case 1:
			//Create new account
			createCustomer(customers);
			Sleep(1500);
			break;
		case 2:
			//Remove account
			deleteCustomer(customers);
			Sleep(1500);
			break;
		case 3:
			//Update name & address for existing customer
			updateCustomer(customers);
			Sleep(1500);
			break;
		case 4:
			//Deposit transaction
			deposit(customers);
			Sleep(1500);
			break;
		case 5:
			//Withdrawl transaction
			withdrawl(customers);
			Sleep(1500);
			break;
		case 6:
			//List information of existing customer
			viewCustomerInfo(customers);
			Sleep(1500);
			break;
		case 7:
			//List customer names and ids
			listCustomers(customers);
			Sleep(1500);
			break;
		case 8:
			//Exit program and write all customers to csv file
			stop(customers);
			break;
			return 0;
		}
	}
	return 0;
}

//Starts program will now load all customers into a vector of customer objects
void start(vector<Customer>& customers) {
	fstream fin;
	fin.open("customer.csv", ios::out | ios::app);

	vector<vector<string>> content;
	vector<string> row;
	string line, word;

	fstream file("customer.csv", ios::in);
	if (file.is_open()) {
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else {
		cout << "Could not open the file\n";
	}
	for (int i = 0; i < content.size(); i++) {
		customers.push_back(Customer(stoi(content[i][0]), content[i][1], content[i][2], stoi(content[i][3]), content[i][4], content[i][5], stoi(content[i][6]), stoi(content[i][7])));
	}

	fin.close();
}

//Loads the Welcome menu
int menu() {
	system("cls");
	cout << "Lawrence Tech Employee Credit Union" << endl;
	cout << "***** Welcome to the Main Menu *****" << endl << endl;
	cout << "1. Create a new checking account." << endl;
	cout << "2. Remove an existing account." << endl;
	cout << "3. Update information for an existing customer." << endl;
	cout << "4. Deposit transaction." << endl;
	cout << "5. Withdrawal transaction. " << endl;
	cout << "6. List information of an existing customer." << endl;
	cout << "7. List customer names and ids." << endl;
	cout << "8. Exit the program. " << endl << endl << endl;

	cout << "Enter your choice (1-8): ";
	int choice;
	cin >> choice;
	while (choice < 1 && choice>8) {
		cout << "Invalid choice. Please try again." << endl;
		cout << "Enter your choice, using a number 1 - 8: __";
		cin >> choice;
	}
	return choice;
}

//Creates a new customer
void createCustomer(vector<Customer>& customers) {
	system("cls");

	int id = 0;
	string name;
	string dob;			//Customer Date of Birth
	int ssn;			//Customer Social Security Numberd
	string address;
	string phoneNumber;
	int typeAccount;	//1 for Checkings, 2 for Savings
	int money;
	int newCustID = 1000;

	for (int i = 0; i < customers.size(); i++) {
		id = customers[i].getId() + 1;
	}

	cout << "What is the name going on the account?" << endl;
	cin.ignore();
	getline(cin, name);
	cout << endl << "What is your date of birth? (mm/dd/yyyy)" << endl;
	getline(cin, dob);
	cout << endl << "What is your Social Security Number? No dashes." << endl;
	cin >> ssn;
	cout << endl << "What is your address?" << endl;
	cin.ignore();
	getline(cin, address);
	cout << endl << "What is your phone Number? " << endl;
	getline(cin, phoneNumber);
	cout << endl << "Is this a checkings or savings account? (1 for Checkings, 2 for Savings)" << endl;
	cin >> typeAccount;
	cout << endl << "How much money are you depositing?" << endl;
	cin >> money;
	customers.push_back(Customer(id, name, dob, ssn, address, phoneNumber, typeAccount, money));
	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";
}

//Deletes an existing customer
void deleteCustomer(vector<Customer>& customers)
{
	int DeleteID;

	system("cls");
	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	vector<vector<string>> information;
	vector<string> row;
	string line, word;
	int count = 0;

	cout << "What account do you want to delete. Please Enter ID ." << endl;
	cin >> DeleteID;

	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getId() == DeleteID) {
			count = 1;
			customers.erase(customers.begin() + i);
		}
	}

	if (count == 0)
	{
		cout << "Account number does not match an existing customer." << endl;
	}
	cout << "Account Removed. Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";
}

//Updates a current customers information
void updateCustomer(vector<Customer>& customers)
{
	system("cls");

	int ChangeID, option, count = 0;
	string NewData;


	cout << "Please enter ID number of account." << endl;
	cin >> ChangeID;

	cout << "What do you want to change(1 - Address, 2 - Phone number)";
	cin >> option;

	cout << "what is the new data?" << endl;
	cin.ignore();
	getline(cin, NewData);

	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getId() == ChangeID) {
			count = 1;
			if (option == 1) {
				customers[i].setAddress(NewData);
			}
			else if (option == 2) {
				customers[i].setNumber(NewData);
			}
		}
	}

	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";
}

//Record a deposit transaction
void deposit(vector<Customer>& customers)
{
	system("cls");

	int ChangeID, Newtotal, NewMoney, count = 0;

	cout << "Please enter account ID." << endl;
	cin >> ChangeID;

	cout << "How much would you like to enter?" << endl;
	cin >> NewMoney;

	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getId() == ChangeID) {
			count = 1;
			Newtotal = customers[i].getMoney() + NewMoney;
			customers[i].setMoney(Newtotal);
		}
	}

	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon." << endl;

}

//Records a withdrawl transaction
void withdrawl(vector<Customer>& customers)
{
	system("cls");
	int ChangeID, NewMoney, NewTotal, count = 0;

	cout << "Please enter your account ID" << endl;
	cin >> ChangeID;

	cout << "How much money would you like to withdraw." << endl;
	cin >> NewMoney;

	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getId() == ChangeID) {
			count = 1;
			NewTotal = customers[i].getMoney() - NewMoney;
			customers[i].setMoney(NewTotal);
		}
	}

	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon." << endl;
}

//Shows all information about a customer
void viewCustomerInfo(vector<Customer>& customers) {
	//displays all information about a chosen customer
	system("cls");
	int test;
	int count = 0;

	int id;
	cout << "Who would you like to look up? Please enter customer id: ";
	cin >> id;

	for (int i = 0; i < customers.size(); i++) {
		if (id == customers[i].getId()) {
			count = 1;
			customers[i].printPerson();		//Overidden print function
		}
	}
	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}
	system("pause");

}

void sortAccountID(vector<Customer>& customers)
{
	vector<Customer> printVector;
	for (int i = 0; i < customers.size(); i++) {
		printVector.push_back(customers[i]);
	}

	for (int i = 0; i < printVector.size()-1; i++) {
		for (int j = 0; j < printVector.size() - 1; j++) {
			if (printVector[j].getId() > printVector[j + 1].getId()) {
				swap(printVector[j], printVector[j + 1]);
			}
		}
	}

	for (int i = 0; i < printVector.size(); i++) {
		cout << "Customer name: " << printVector[i].getName() << endl;
		cout << "Customer ID: " << printVector[i].getId() << endl << endl;
	}

}

void sortName(vector<Customer>& customers)
{
	vector<Customer> printVector;
	for (int i = 0; i < customers.size(); i++) {
		printVector.push_back(customers[i]);
	}

	for (int i = 0; i < printVector.size() - 1; i++) {
		for (int j = 0; j < printVector.size() - 1; j++) {
			if (printVector[j].getName() > printVector[j + 1].getName()) {
				swap(printVector[j], printVector[j + 1]);
			}
		}
	}

	for (int i = 0; i < printVector.size(); i++) {
		cout << "Customer name: " << printVector[i].getName() << endl;
		cout << "Customer ID: " << printVector[i].getId() << endl << endl;
	}

}

//Prints out all customers
void listCustomers(vector<Customer>& customers) {

	int option;
	system("cls");
	cout << "Please choose if you want to sort by ID(1) or Name(2)" << endl;
	cin >> option;
	if (option == 1) {
		sortAccountID(customers);
	}else {
		sortName(customers);
	}
	system("pause");
}

//Ends program
void stop(vector<Customer>& Custs) {
	//terminate program and write all cust info to csv file
	ofstream fileout("customer2.csv");
	fstream file("customer.csv", ios::in);

	for (int i = 0; i < Custs.size(); i++) {
		fileout << Custs[i].getId() << "," << Custs[i].getName() << "," << Custs[i].getDOB() << "," << Custs[i].getSSN() << "," << Custs[i].getAddress() << "," << Custs[i].getNumber() << "," << Custs[i].getAccountType() << "," << Custs[i].getMoney() << '\n';
	}

	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");

	system("cls");
	cout << "Program ended." << endl;
	system("pause");
	return;

}