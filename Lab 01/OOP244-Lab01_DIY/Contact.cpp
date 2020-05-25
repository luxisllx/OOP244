// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Functions related to Contact information

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"
using namespace std;

namespace sdds
{ 

void getContact(Contact* C) {
	cout << "Name: ";
	getName(C->name);
	cout << "Phone Number: ";
	C->phoneNumber = getPhoneNumber();
}

void printContact(const Contact* C) {
	cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
}

void getName(char* name) {
	getStr(name, 30);
}

bool nameInContact(const Contact* C, const char* nameSubStr) {
	char name[31];
	char subName[31];
	toLowerCase(name, C->name);
	toLowerCase(subName, nameSubStr);
	return strstr(name, subName) != nullptr;
}


void printContacts(const Contact* C, int num) {
	for (int i = 0; i < num; i++) {
		printContact(&C[i]);
	}
}
}