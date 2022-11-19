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
using namespace std;

void start(vector<Customer> &);
int menu();
void createCustomer(vector<Customer>&);
void deleteCustomer(vector<Customer>&);
void updateCustomer(vector<Customer>&);
void deposit(vector<Customer>&);
void withdrawl(vector<Customer>&);
void viewCustomerInfo(vector<Customer>&);
void listCustomers(vector<Customer>&);
void stop(vector<Customer>&);


int main() {
	vector<Customer> Custs;
	start(Custs);
	int choice = 0;
	while (choice != 8) {
		choice = menu();
		switch (choice) {
		case 1:
			//Create new account
			createCustomer(Custs);
			Sleep(1500);
			break;
		case 2:
			//Remove account
			deleteCustomer(Custs);
			Sleep(1500);
			break;
		case 3:
			//Update name & address for existing customer
			updateCustomer(Custs);
			Sleep(1500);
			break;
		case 4:
			//Deposit transaction
			deposit(Custs);
			Sleep(1500);
			break;
		case 5:
			//Withdrawl transaction
			withdrawl(Custs);
			Sleep(1500);
			break;
		case 6:
			//List information of existing customer
			viewCustomerInfo(Custs);
			Sleep(1500);
			break;
		case 7:
			//List customer names and ids
			listCustomers(Custs);
			Sleep(1500);
			break;
		case 8:
			//Exit program and write all customers to csv file
			stop(Custs);
			break;
			return 0;
		}
	}
	return 0;
}

//Starts program will now load all customers into a vector of customer objects
void start(vector<Customer>& Custs) {
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
		Custs.push_back(Customer(stoi(content[i][0]), content[i][1], content[i][2], stoi(content[i][3]), content[i][4], content[i][5], stoi(content[i][6]), stoi(content[i][7])));
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
void createCustomer(vector<Customer>& Custs) {
	system("cls");

	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	int id;
	string name;
	string dob;			//Customer Date of Birth
	int ssn;			//Customer Social Security Numberd
	string address;
	string phoneNumber;
	int typeAccount;	//1 for Checkings, 2 for Savings
	int money;
	vector<vector<string>> information;
	int newCustID = 1000;
	vector<string> row;
	string line, word;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			stringstream str(line);
			while (getline(str, word, ','))
				row.push_back(word);
			information.push_back(row);
		}

	}
	else
	{
		cout << "Could not open the file\n";
	}

	for (int i = 0; i < information.size(); i++)
	{
		int next = i + 1;
		newCustID = stoi(information[i][0]);
	}

	id = newCustID + 1;
	for (int i = 0; i < information.size(); i++)
	{
		fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
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
	cout << endl << "What is your phone Number? No dashes." << endl;
	getline(cin, phoneNumber);
	cout << endl << "Is this a checkings or savings account? (1 for Checkings, 2 for Savings)" << endl;
	cin >> typeAccount;
	cout << endl << "How much money are you depositing?" << endl;
	cin >> money;
	fileout << id << "," << name << "," << dob << "," << ssn << "," << address << "," << phoneNumber << "," << typeAccount << "," << money << '\n';
	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";
	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");
}

//Deletes an existing customer
void deleteCustomer(vector<Customer>& Custs)
{
	int DeleteID;

	system("cls");
	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	vector<vector<string>> information;
	vector<string> row;
	string line, word;
	int count = 0;
	if (file.is_open()) {
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				information.push_back(row);
			}
		}
	}
	else {
		cout << "Could not open the file\n";
	}
	cout << "What account do you want to delete. Please Enter ID ." << endl;
	cin >> DeleteID;

	for (int i = 0; i < information.size(); i++)
	{
		int checkID = stoi(information[i][0]);
		if (checkID != DeleteID)
		{
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
		}
		else
			count++;
	}
	if (count == 0)
	{
		cout << "Account number does not match an existing customer." << endl;
	}
	cout << "Account Removed. Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";
	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");
}

//Updates a current customers information
void updateCustomer(vector<Customer>& Custs)
{
	system("cls");
	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	vector<vector<string>> information;
	vector<string> row;
	string line, word;
	int ChangeID, option, count = 0;
	string NewData;

	if (file.is_open()) {
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				information.push_back(row);
			}
		}
	}
	else
	{
		cout << "Could not open the file\n";
	}

	cout << "Please enter ID number of account." << endl;
	cin >> ChangeID;

	cout << "what do you want to change(1- Address 2-Phone number";
	cin >> option;

	cout << "what is the new data?" << endl;
	cin.ignore();
	getline(cin, NewData);


	for (int i = 0; i < information.size(); i++)
	{
		int checkID = stoi(information[i][0]);
		if (checkID == ChangeID)
		{
			if (option == 1)
			{
				fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << NewData << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
			}
			else
				fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << NewData << "," << information[i][6] << "," << information[i][7] << '\n';
			count++;
		}
		else
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
	}
	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon.";

	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");
}

//Record a deposit transaction
void deposit(vector<Customer>& Custs)
{
	system("cls");
	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	vector<vector<string>> information;
	vector<string> row;
	string line, word;
	int ChangeID, Newtotal, NewMoney, count = 0;

	if (file.is_open())
	{
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				information.push_back(row);
			}
		}
	}
	else
	{
		cout << "Could not open the file\n";
	}

	cout << "Please enter account ID." << endl;
	cin >> ChangeID;

	cout << "How much would you like to enter?" << endl;
	cin >> NewMoney;

	for (int i = 0; i < information.size(); i++)
	{
		int checkID = stoi(information[i][0]);
		if (checkID == ChangeID)
		{
			count++;
			Newtotal = stoi(information[i][7]) + NewMoney;
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << Newtotal << '\n';
		}
		else
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
	}
	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon." << endl;

	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");
}

//Records a withdrawl transaction
void withdrawl(vector<Customer>& Custs)
{
	system("cls");
	fstream file("customer.csv", ios::in);
	ofstream fileout("customer2.csv");

	vector<vector<string>> information;
	vector<string> row;
	string line, word;
	int ChangeID, NewMoney, NewTotal, count = 0;
	if (file.is_open()) {
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				information.push_back(row);
			}
		}
	}
	else {
		cout << "Could not open the file\n";
	}
	cout << "Please enter your account ID" << endl;
	cin >> ChangeID;

	cout << "How much money would you like to withdraw." << endl;
	cin >> NewMoney;

	for (int i = 0; i < information.size(); i++)
	{
		int checkID = stoi(information[i][0]);
		if (checkID == ChangeID)
		{
			NewTotal = stoi(information[i][7]) - NewMoney;
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << NewTotal << '\n';
			count = 1;
		}
		else
			fileout << information[i][0] << "," << information[i][1] << "," << information[i][2] << "," << information[i][3] << "," << information[i][4] << "," << information[i][5] << "," << information[i][6] << "," << information[i][7] << '\n';
	}

	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}

	cout << "Thank you for working with Lawrence Tech credit union. You are all set, please come back soon." << endl;
	file.close();
	fileout.close();
	remove("customer.csv");
	rename("customer2.csv", "customer.csv");
}

//Shows all information about a customer
void viewCustomerInfo(vector<Customer>& Custs) {
	//displays all information about a chosen customer
	system("cls");
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	int test;
	int count = 0;

	fstream file("customer.csv", ios::in);
	int id;
	cout << "Who would you like to look up? Please enter customer id: ";
	cin >> id;

	if (file.is_open()) {
		{
			while (getline(file, line))
			{
				row.clear();

				stringstream str(line);

				while (getline(str, word, ','))
					row.push_back(word);
				content.push_back(row);
			}
		}
	}
	else {
		cout << "Could not open the file\n";
	}

	for (int i = 0; i < content.size(); i++) {
		for (int j = 0; j < content[i].size(); j++) {
			test = stoi(content[i][0]);
			if (test == id) {
				count = 1;
				cout << "Customer ID: " << content[i][0] << endl;
				cout << "Customer Name: " << content[i][1] << endl;
				cout << "Customer Date of Birth: " << content[i][2] << endl;
				cout << "Customer SSN: " << content[i][3] << endl;
				cout << "Customer Address: " << content[i][4] << endl;
				cout << "Customer Phone Number: " << content[i][5] << endl;
				int type = atoi(content[i][6].c_str());
				if (type == 1) {
					cout << "Customers account type: Checkings" << endl;
				}
				else if (type == 2) {
					cout << "Customers account type: Savings" << endl;
				}
				cout << "Customer Account Balance: $" << content[i][7] << endl;
				break;
			}
		}
		cout << "\n";
	}
	if (count == 0) {
		cout << "Account number does not match an existing customer." << endl;
	}
	system("pause");

}

//Prints out all customers
void listCustomers(vector<Customer>& Custs) {
	system("cls");
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
		cout << "Customer name: " << content[i][1] << endl;
		cout << "Customer ID: " << content[i][0] << endl << endl;
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