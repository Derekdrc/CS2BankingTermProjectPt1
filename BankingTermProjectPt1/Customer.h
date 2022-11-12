#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer
{
private:
	int id; // Customer ID number
	string name;
	string dob; // Customer Date of Birth
	int ssn;	// Customer Social Security Number
	string address;
	string phoneNumber;
	int typeAccount; // 1 for Checkings, 2 for Savings
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
		typeAccount = NULL;
		money = NULL;
	}

	// Constructor with all information given
	Customer(int idNum, string custName, string birthDate, int social, string streetAdd, string number, int type, int dollars)
	{
		id = idNum;
		name = custName;
		dob = birthDate;
		ssn = social;
		address = streetAdd;
		phoneNumber = number;
		typeAccount = type;
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

	void setAccountType(int s)
	{
		typeAccount = s;
	}

	void setMoney(int s)
	{
		money = s;
	}
};

#endif #pragma once
