// COURSE: OOP244 LAB 03
// NAME: LUXI LIANG
// STUDENT #: 216936188
// DATE: 10-01-2019


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Mark.h"
#include "MarksReport.h"
#include "ReportUtils.h"

using namespace std;

namespace sdds {

	void MarksReport::initialize() {		//this function was not necessary for my code

	}


	void MarksReport::getMarks() {		// stores the value of report name and marks

		cout << "Enter the report Name: ";

		cin.getline(title, 71);
		//cin.ignore();
		//cin.clear();
		//flushKeyboard();

		cout << "Enter the number of marks: ";
		cin >> numMarks;
		cin.clear();
		flushKeyboard();

		cout << "Please enter " << numMarks << " marks:" << endl;

		marks = new Mark[numMarks];
		const char* subject = "Subject Name: ";
		const char* prompt = "Mark (mark/outof): ";

		for (int i = 0; i < numMarks; i++) {
			cout << i+1 <<": ";
			marks[i].readName(subject);
			
			marks[i].read(prompt);
		}

		cout << "Entry Completed!" << endl;
		cout << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}
	void MarksReport::print() {			// prints the total report of marks 

		cout << title << endl;
		cout << "----------------------------------------------------------------------" << endl;
		cout << "Marks entered:" << endl;

		
		int smallest = marks[0].percent();		//finding smallest mark
		int largest = marks[0].percent();		// finding largest mark
		
		double average;
		double sum = 0;

		for (int i = 0; i < numMarks; i++) {		// for loop to find smallest, largest, and GPA average

			marks[i].set(DSP_LETTER);
			marks[i].display(66);
			cout << endl;

			if (marks[i].percent() < smallest) {	
					smallest = marks[i].percent();
			}

			if (marks[i].percent() > largest) {
					largest = marks[i].percent();

			}

			marks[i].letterBasedGPA();			// storing values of grades into letterBasedGPA
			
			sum += marks[i].letterBasedGPA();	// getting sum of all marks

			average = sum / numMarks;			// getting average of all marks
				
		}
			cout << "----------------------------------------------------------------------" << endl;
			cout << "                              Lowest Mark.........................%" << smallest << endl;
			cout << "                              Highest mark........................%" << largest << endl;
			cout << "                              GPA................................." << std::fixed << std::setprecision(1) << average << endl;

			
	}
	void MarksReport::terminate() {		// deletes allocated memory for marks

		delete[] marks;

	}




}