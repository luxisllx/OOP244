#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SCHOOL_H
#define SDDS_SCHOOL_H
#include <iostream>
#include "utils.h"
#include "Subject.h"


namespace sdds {

	struct School {
		int m_noOfSubjects;
		Subject* m_subjects;
		char* m_name;
	};

	void read(School&);
	int report(const School&);
	void freeMem(School&);


}
#endif