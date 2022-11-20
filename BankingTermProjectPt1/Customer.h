#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Person {
private:
	string name;
	string dob; // Customer Date of Birth
	int ssn;	// Customer Social Security Number
	string address;
	string phoneNumber;

public:
	// Default Constructor
	Person()
	{
		name = " ";
		dob = " ";
		ssn = NULL;
		address = " ";
		phoneNumber = " ";
	}

	// Constructor with all information given
	Person(string custName, string birthDate, int social, string streetAdd, string number)
	{
		name = custName;
		dob = birthDate;
		ssn = social;
		address = streetAdd;
		phoneNumber = number;

	}

	// Getters
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

	// Setters
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

	virtual void printPerson() {
		cout << "Person's Name: " << getName() << endl;
		cout << "Person's Date of Birth: " << getDOB() << endl;
		cout << "Person's SSN: " << getSSN() << endl;
		cout << "Person's Address: " << getAddress() << endl;
		cout << "Person's Phone Number: " << getNumber() << endl << endl;
	}

};


class Customer : public Person
{
private:
	int id; // Customer ID number
	int typeAccount; // 1 for Checkings, 2 for Savings
	int money;

public:
	// Default Constructor
	Customer()
	{
		id = NULL;
		typeAccount = NULL;
		money = NULL;
	}

	// Constructor with all information given
	Customer(int idNum, string custName, string birthDate, int social, string streetAdd, string number, int type, int dollars) : Person(custName, birthDate, social, streetAdd, number)
	{
		id = idNum;
		typeAccount = type;
		money = dollars;
	}

	// Getters
	int getId()
	{
		return id;
	}

	int getAccountType()
	{
		return typeAccount;
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

	void setAccountType(int s)
	{
		typeAccount = s;
	}

	void setMoney(int s)
	{
		money = s;
	}

	virtual void printPerson() {
		cout << "Customer ID: " << getId() << endl;
		cout << "Customer Name: " << getName() << endl;
		cout << "Customer Date of Birth: " << getDOB() << endl;
		cout << "Customer SSN: " << getSSN() << endl;
		cout << "Customer Address: " << getAddress() << endl;
		cout << "Customer Phone Number: " << getNumber() << endl;
		if (getAccountType() == 1) {
			cout << "Customers account type: Checkings" << endl;
		}
		else if (getAccountType() == 2) {
			cout << "Customers account type: Savings" << endl;
		}
		cout << "Customer Account Balance: $" << getMoney() << endl;
	}
};

class Employee : public Person {
private:
	int employeeId;
	double payRate;

public:
	// Default Constructor
	Employee()
	{
		employeeId = NULL;
		payRate = NULL;
	}

	// Constructor with all information given
	Employee(int employeeId, string custName, string birthDate, int social, string streetAdd, string number, double payRate) : Person(custName, birthDate, social, streetAdd, number)
	{
		employeeId = employeeId;
		payRate = payRate;
	}

	//getters
	int getEmployeeId() {
		return employeeId;
	}

	int getPayRate() {
		return payRate;
	}

	//Setters
	void setEmployeeId(int id) {
		employeeId = id;
	}

	void setPayRate(double pay) {
		payRate = pay;
	}

	virtual void printPerson() {
		cout << "Employee ID: " << getEmployeeId() << endl;
		cout << "Customer Name: " << getName() << endl;
		cout << "Customer Date of Birth: " << getDOB() << endl;
		cout << "Customer SSN: " << getSSN() << endl;
		cout << "Customer Address: " << getAddress() << endl;
		cout << "Customer Phone Number: " << getNumber() << endl;
		cout << "Employee Pay Rate: $" << getPayRate() << " /hr. " << endl;
	}
};

#endif #pragma once