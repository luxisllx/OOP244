#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Subject.h" 
#include "utils.h"

namespace sdds {

	// Limits user input of subject name and sends error message when exceeded limit
	void read(char* one) {
		cout << "Enter subject name: ";


		int len;
		const char* errormessage;

		len = 70;
		errormessage = "Name is too long, only 70 characters allowed!\nRedo Entry: ";
		read(one, len, errormessage);


	}
	// Limits user input of section number and gives error message when exceeded
	void read(int& two) {
		cout << "Enter number of sections: ";

		int val;
		int min;
		int max;
		const char* ErrorMess;

		min = 1;
		max = 10;
		ErrorMess = "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ";
		read(val, min, max, ErrorMess);

		two = val;

	}
	// Read number of student in each section and total number of sections 
	void read(int x[], int three) {


		cout << "Enter the number of students in each one of the " << three << " sections:" << endl;

		int i;
		int val;
		int min;
		int max;
		const char* ErrorMess;

		min = 5;
		max = 35;
		ErrorMess = "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ";

		for (i = 0; i < three; i++) {
			cout << i + 1 << ": ";
			read(val, min, max, ErrorMess);
			x[i] = val;

		}

	}
	// Reads the subject, set the allocating dynamic memory and setting to each member
	//It is a wrapper function to the other functions
	void read(Subject& Sub) {

		char setup[71];

		read(setup);
		int passing;

		Sub.m_subjectName = new char[71];
		strcpy(Sub.m_subjectName, setup);

		Sub.m_noOfSections = new int;
		read(passing);
		*Sub.m_noOfSections = passing;

		Sub.m_noOfStdsInSecs = new int[passing];
		read(Sub.m_noOfStdsInSecs, passing);
	}
	// Reports the final stats of student enrollment and total student enrollment
	int report(const Subject& conclusion) {

		int i;
		int totalenroll;

		totalenroll = 0;
		for (i = 0; i < *conclusion.m_noOfSections; i++)
		{
			if (i == *conclusion.m_noOfSections - 1)
				cout << conclusion.m_noOfStdsInSecs[i];
			else
				cout << conclusion.m_noOfStdsInSecs[i] << ",";
			totalenroll = totalenroll + conclusion.m_noOfStdsInSecs[i];

		}
		cout << endl;
		cout << conclusion.m_subjectName << ": " << totalenroll << endl;

		return totalenroll;
	}
	// Deletes all allocating dynamic memory 
	void freeMem(Subject& deleting) {
		delete[] deleting.m_subjectName;
		delete deleting.m_noOfSections;
		delete[] deleting.m_noOfStdsInSecs;
	}
}
