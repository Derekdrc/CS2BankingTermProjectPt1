#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
private:
	string name;
	string dob;			//Customer Date of Birth
	int ssn;			//Customer Social Security Number
	string address;
	int phoneNumber;
	int typeAccount;	//1 for Checkings, 2 for Savings

public:
	//Default Constructor
	Customer() {
		name = " ";
		dob = " ";
		ssn = NULL;
		address = " ";
		phoneNumber = NULL;
		typeAccount = NULL;
	}

	//Constructor with all information given
	Customer(string custName, string birthDate, int social, string streetAdd, int number, int type) {
		name = custName;
		dob = birthDate;
		ssn = social;
		address = streetAdd;
		phoneNumber = number;
		typeAccount = type;
	}


};





#endif