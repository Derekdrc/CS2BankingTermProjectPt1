//Derek D'Arcy & Angela Ladd
//CS2 Term Project Pt 1
//Banking Management System

#include "Customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void start();
int menu();
void createCustomer();
void deleteCustomer();
void updateCustomer();
void deposit();
void withdrawl();
void viewCustomerInfo();
void listCustomers();
void stop();


int main() {
	start();
	int choice = menu();
	switch (choice) {
		case 1:
			//Create new account
			createCustomer();
			break;
		case 2:
			//Remove account
			deleteCustomer();
			break;
		case 3:
			//Update name & address for existing customer
			updateCustomer();
			break;
		case 4:
			//Deposit transaction
			deposit();
			break;
		case 5:
			//Withdrawl transaction
			withdrawl();
			break;
		case 6:
			//List information of existing customer
			viewCustomerInfo();
			break;
		case 7:
			//List customer names and ids
			listCustomers();
			break;
		case 8:
			//Exit program and write all customers to csv file
			stop();
			break;
			return 0;
	}


}

//Starts program and loads existing csv file, or creates new one if one does not exist
void start() {
	fstream fin;
	fin.open("customer.csv", ios::in | ios::out | ios::app);

}

//Loads the Welcome menu
int menu() {
	system("cls");
	cout << "Lawrence Tech Employee Credit Union" << endl;
	cout << "***** Welcome to the Main Menu *****" << endl << endl;
	cout << "1. Create a new checking account." << endl;
	cout << "2. Remove an existing account." << endl;
	cout << "3. Update name, address information for an existing customer." << endl;
	cout << "4. Deposit transaction." << endl;
	cout << "5. Withdrawal transaction. " << endl;
	cout << "6. List information of an existing customer." << endl;
	cout << "7. List customer names and ids." << endl;
	cout << "8. Exit the program. " << endl << endl << endl;

	cout << "Enter your choice (1-8): __ "; 
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
void createCustomer() {

}

//Deletes an existing customer
void deleteCustomer() {

}

//Updates a current customers information
void updateCustomer() {

}

//Record a deposit transaction
void deposit() {

}

//Records a withdrawl transaction
void withdrawl() {
	//choose a customer and then subtract the amount they wish to withdrawl
}

//Shows all information about a customer
void viewCustomerInfo() {
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
	} else {
		cout << "Could not open the file\n";
	}

	for (int i = 0; i < content.size(); i++) {
		for (int j = 0; j < content[i].size(); j++) {
			test = stoi(content[i][0]);
			if (test == id) {
				count = 1;
				cout << "Customer ID: " << content[i][0] << endl;
				cout << "Customer name: " << content[i][1] << endl;
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

}

//Prints out all customers
void listCustomers() {
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
	} else {
		cout << "Could not open the file\n";
	}

	for (int i = 0; i < content.size(); i++) {
			cout << "Customer name: " << content[i][1] <<endl;
			cout << "Customer ID: " << content[i][0] << endl << endl;
	}
}

//Ends program
void stop() {
	//terminate program and write all cust info to csv file

	system("cls");
	cout << "Program ended." << endl;
	system("pause");
	return; 

}