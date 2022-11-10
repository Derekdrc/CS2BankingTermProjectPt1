#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
private:
	int id;				//Customer ID number
	string name;
	string dob;			//Customer Date of Birth
	int ssn;			//Customer Social Security Number
	string address;
	int phoneNumber;
	int typeAccount;	//1 for Checkings, 2 for Savings
	int money;

public:
	//Default Constructor
	Customer() {
		id = NULL;
		name = " ";
		dob = " ";
		ssn = NULL;
		address = " ";
		phoneNumber = NULL;
		typeAccount = NULL;
		money = NULL;
	}

	//Constructor with all information given
	Customer(int idNum, string custName, string birthDate, int social, string streetAdd, int number, int type, int dollars) {
		id = idNum;
		name = custName;
		dob = birthDate;
		ssn = social;
		address = streetAdd;
		phoneNumber = number;
		typeAccount = type;
		money = dollars;
	}


};

#endif