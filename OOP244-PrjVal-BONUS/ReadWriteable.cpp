// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
using namespace std;
#include "ReadWriteable.h"
namespace sdds {

	ostream& operator<<(ostream& output, const ReadWriteable& R) {
		R.write(output);
		return output;
	}

	istream& operator>>(istream& input, ReadWriteable& R) {
		R.read(input);
		return input;
	}
}
