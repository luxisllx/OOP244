// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Tools.h
// Organized prototype for Tools function

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_Tools_H
#define SDDS_Tools_H

#include "Contact.h"

namespace sdds {

	bool valid(long long min, long long max, long long val);

	long long getLongLong(long long min, long long max, const char* valueName);
	
	long long getPhoneNumber();

	void getStr(char* str, int len);

	int search(Contact* found, const Contact* C, const char* name, int noOfRecs);

	void sort(Contact c[], int n);

	void toLowerCase(char* lowerCase, const char* str);

	bool yes();
}
#endif
