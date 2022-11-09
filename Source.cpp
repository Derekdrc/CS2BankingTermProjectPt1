//Derek D'Arcy & Angela Ladd
//CS2 Term Project Pt 1
//Banking Management System

#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;

void StartPgm();
int Menu();
void NewCust();
void delCust();
void UpdCustInfo();
void deposit();
void withdrawl();
void viewCustInfo();
void listCustomers();
void StopPgm();


int main() {
	StartPgm();
	int choice = Menu();
	switch (choice) {
		case 1:
			//Create new account
			NewCust();
			break;
		case 2:
			//Remove account
			delCust();
			break;
		case 3:
			//Update name & address for existing customer
			UpdCustInfo();
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
			viewCustInfo();
			break;
		case 7:
			//List customer names and ids
			listCustomers();
			break;
		case 8:
			//Exit program
			StopPgm();
			break;

	}


}

//Starts program and loads existing csv file, or creates new one if one does not exist
void StartPgm() {
	fstream fin;
	fin.open("customer.csv", ios::in | ios::out | ios::app);

}

//Loads the Welcome menu
int Menu() {
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
void NewCust() {

}

//Deletes an existing customer
void delCust() {

}

//Updates a current customers information
void UpdCustInfo() {

}

//Record a deposit transaction
void deposit() {

}

//Records a withdrawl transaction
void withdrawl() {

}

//Shows all information about a customer
void viewCustInfo() {

}

//Prints out all customers
void listCustomers() {

}

//Ends program
void StopPgm() {

}