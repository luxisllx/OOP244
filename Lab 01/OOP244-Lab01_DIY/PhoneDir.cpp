// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Functions related to Phone Directory information


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "PhoneDir.h"
#include "Tools.h"
#include "File.h"
#include "Contact.h"

using namespace std;
namespace sdds 
{

	int menu() {
		cout << endl
			<< "1- Add Phone Record " << endl;
		cout << "2- Search           " << endl;
		cout << "3- Sort             " << endl;
		cout << "4- List all         " << endl;
		cout << "0- Exit             " << endl;
		cout << "> ";
		return int(getLongLong(0, 4, "option"));
	}

	int compare(const Contact* A, const Contact* B) {
		return strcmp(A->name, B->name);
	}
	
	void phoneDir(const char* title, const char* filename) {
		int option;
		Contact C[MAX_REC_NO];
		Contact SearchRes[MAX_REC_NO];
		Contact temp;
		bool changed = false;
		int noOfRecs = readContacts(C, filename);
		int noOfSrchs;
		cout << title << ".................." << endl;
		do {
			switch (option = menu()) {
			case 0:
				cout << "Goodbye!" << endl;
				break;
			case 1: // add
				getContact(&temp);
				C[noOfRecs] = temp;
				noOfRecs++;
				changed = true;
				break;
			case 2: // search
				cout << "Name to search for: ";
				getStr(temp.name, 30);
				noOfSrchs = search(SearchRes, C, temp.name, noOfRecs);
				if (noOfSrchs) {
					printContacts(SearchRes, noOfSrchs);
				}
				else {
					cout << temp.name << ", not found!" << endl;
				}
				break;
			case 3:  // Sort
				sort(C, noOfRecs);
				cout << "Sorted!" << endl;
				changed = true;
				break;
			case 4:
				printContacts(C, noOfRecs);
				break;
			}
		} while (option);
		if (changed) {
			cout << endl << "The phone diecotry has changed!" << "Save changes? (Y/N): ";
			if (yes()) {
				writeContacts(C, noOfRecs, filename);
				cout << "Changes Saved!!" << endl;
			}
			else {
				cout << "Changes aborted!!" << endl;
			}
		}
	}
}