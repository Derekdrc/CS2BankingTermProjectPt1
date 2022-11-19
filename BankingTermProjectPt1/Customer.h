#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer
{
private: //Assume checking account, inherit saavings account
	int id; // Customer ID number
	string name;
	string dob; // Customer Date of Birth
	int ssn;	// Customer Social Security Number
	string address;
	string phoneNumber;
	int money;

public:
	// Default Constructor
	Customer()
	{
		id = NULL;
		name = " ";
		dob = " ";
		ssn = NULL;
		address = " ";
		phoneNumber = " ";
		money = NULL;
	}

	// Constructor with all information given
	Customer(int idNum, string custName, string birthDate, int social, string streetAdd, string number, int dollars)
	{
		id = idNum;
		name = custName;
		dob = birthDate;
		ssn = social;
		address = streetAdd;
		phoneNumber = number;
		money = dollars;
	}

	// Getters
	int getId()
	{
		return id;
	}

	string getName()
	{
		return name;
	}

	string getDOB()
	{
		return dob;
	}

	int getSSN()
	{
		return ssn;
	}

	string getAddress()
	{
		return address;
	}

	string getNumber()
	{
		return phoneNumber;
	}

	int getMoney()
	{
		return money;
	}

	// Setters
	void setId(int s)
	{
		id = s;
	}

	void setName(string s)
	{
		name = s;
	}

	void setDOB(string s)
	{
		dob = s;
	}

	void setSSN(int s)
	{
		ssn = s;
	}

	void setAddress(string s)
	{
		address = s;
	}

	void setNumber(string s)
	{
		phoneNumber = s;
	}

	void setMoney(int s)
	{
		money = s;
	}

	virtual void printCustomer() {
		cout << "Customer ID: " << getId() << endl;
		cout << "Customer Name: " << getName() << endl;
		cout << "Customer Date of Birth: " << getDOB() << endl;
		cout << "Customer SSN: " << getSSN() << endl;
		cout << "Customer Address: " << getAddress() << endl;
		cout << "Customer Phone Number: " << getNumber() << endl;
		cout << "Customer Account type: Checkings" << endl;
		cout << "Customer Account Balance: $" << getMoney() << endl;
	}
};


class SavingsAccount : public Customer {
private:
	bool savings;
public:
	//default constructor
	SavingsAccount() {
		savings = true;
	}

	//parameter constructor
	SavingsAccount(int idNum, string custName, string birthDate, int social, string streetAdd, string number, int dollars, bool savings) : Customer(idNum, custName, birthDate, social, streetAdd, number, dollars) {
		savings = savings;
	}

	bool getSavingsType() {
		return savings;
	}

	bool setSavingsType(bool isSavings) {
		savings = isSavings;
	}

	virtual void printCustomer() {
		cout << "Customer ID: " << getId() << endl;
		cout << "Customer Name: " << getName() << endl;
		cout << "Customer Date of Birth: " << getDOB() << endl;
		cout << "Customer SSN: " << getSSN() << endl;
		cout << "Customer Address: " << getAddress() << endl;
		cout << "Customer Phone Number: " << getNumber() << endl;
		if (getSavingsType) {
			cout << "Customer Account type: Savings" << endl;
		}
		else {
			cout << "Customer Account type: Checkings" << endl;
		}
		cout << "Customer Account Balance: $" << getMoney() << endl;
	}
};

class CheckingAccount : public Customer {
private:
	bool savings;
public:
	//default constructor
	CheckingAccount() {
		savings = true;
	}

	//parameter constructor
	CheckingAccount(int idNum, string custName, string birthDate, int social, string streetAdd, string number, int dollars, bool checking) : Customer(idNum, custName, birthDate, social, streetAdd, number, dollars) {
		savings = savings;
	}

	bool getAccountType() {
		return savings;
	}

	bool setAccountType(bool isSavings) {
		savings = isSavings;
	}

	virtual void printCustomer() {
		cout << "Customer ID: " << getId() << endl;
		cout << "Customer Name: " << getName() << endl;
		cout << "Customer Date of Birth: " << getDOB() << endl;
		cout << "Customer SSN: " << getSSN() << endl;
		cout << "Customer Address: " << getAddress() << endl;
		cout << "Customer Phone Number: " << getNumber() << endl;
		if (getAccountType) {
			cout << "Customer Account type: Savings" << endl;
		}
		else {
			cout << "Customer Account type: Checkings" << endl;
		}
		cout << "Customer Account Balance: $" << getMoney() << endl;
	}
};

class CustomerList {
private:
	vector<Customer*> customers;

public:
	Customer* AddCheckingAccount(const int& idNum, string& custName, string& birthDate, int& social, string& streetAdd, string& number, int& dollars, bool& checking) {
		Customer* a = new CheckingAccount(idNum, custName, birthDate, social, streetAdd, number, dollars, checking);
		customers.push_back(a);
		return a;
	}

	~CustomerList() {
		size_t sz = customers.size();
		for (size_t i = 0; i < sz; ++i)
			delete customers[i];
	}
};

#endif #pragma once
