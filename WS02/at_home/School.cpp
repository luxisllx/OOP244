#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Subject.h" 
#include "utils.h"
#include "School.h"
using namespace std;

namespace sdds {

	// This function takes user input for school name and number of subject offered
	// Shows error message if input is out of specified range
	void read(School& Sch) {

		char arri[61];

		cout << "Please enter the name of the school:\n> ";

		
		read(arri, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: ");

		Sch.m_name = new char[strlen(arri) + 1];
		strcpy(Sch.m_name, arri);

		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";

		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");

		Sch.m_subjects = new Subject[Sch.m_noOfSubjects];


		for (int i = 0; i < Sch.m_noOfSubjects; i++) {
			cout << i + 1 << ") ------------------------------" << endl;
			read(Sch.m_subjects[i]);
		}
	}
	// Function gives result of total subject enrollments
	int report(const School& reports) {
		cout << reports.m_name << endl;
		cout << "Subject Enrollments" << endl;

		int totalreport = 0;
		for (int i = 0; i < reports.m_noOfSubjects; i++) {

			totalreport = totalreport + report(reports.m_subjects[i]);
		}
		cout << "Total enrollment: " << totalreport << endl;

		return totalreport;

	}
	// Function deletes allocated dynamic memory 
	void freeMem(School& deleted) {
		delete[] deleted.m_name;
		for (int i = 0; i < deleted.m_noOfSubjects; i++) {
			freeMem(deleted.m_subjects[i]);
		}
		delete[] deleted.m_subjects;

	}
}