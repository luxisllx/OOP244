// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Functions that are used as Tools


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Tools.h"
#include "PhoneDir.h"

using namespace std;

namespace sdds
{
	bool valid(long long min, long long max, long long val) {
		return min <= val && val <= max;
	}

	long long getLongLong(long long min, long long max, const char* valueName) {
		long long val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				if (!valid(min, max, val)) {
					cout << "Invalid " << valueName << "!" << endl
						<< "The " << valueName << " must be between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}

	long long getPhoneNumber() {
		return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
	}

	void getStr(char* str, int len) {
		cin.getline(str, len, '\n');
	}

	int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
		int i;
		int noOfMatches = 0;
		for (i = 0; i < noOfRecs; i++) {
			if (nameInContact(&C[i], name)) {
				found[noOfMatches] = C[i];
				noOfMatches++;
			}
		}
		return noOfMatches;
	}

	void sort(Contact c[], int n) {
		Contact temp;
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (compare(&c[j], &c[j + 1]) > 0) {
					temp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = temp;
				}
			}
		}
	}

	void toLowerCase(char* lowerCase, const char* str) {
		int i;
		for (i = 0; str[i] && i < 30; i++) {
			lowerCase[i] = str[i] | 0x20;
		}
		lowerCase[i] = 0;
	}

	bool yes() {
		char ch;
		ch = cin.get();
		cin.ignore(1000, '\n');
		return ch == 'y' || ch == 'Y';
	}
}