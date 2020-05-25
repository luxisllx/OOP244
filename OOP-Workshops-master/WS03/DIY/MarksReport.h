// COURSE: OOP244 LAB 03
// NAME: LUXI LIANG
// STUDENT #: 216936188
// DATE: 09-28-2019

#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H
#include <iostream>
#include <string>
#include "Mark.h"

using namespace std;
namespace sdds {


	class MarksReport {

		Mark* marks;
		char title[71];
		int numMarks;

	public:
		void initialize();
		void getMarks();
		void print();
		void terminate();

	};
}
#endif


