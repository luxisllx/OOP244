// Luxi Liang
// OOP244 Lab08
// 11/20/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Pen.h"

namespace sdds {

	// constructor
	Pen::Pen() {

		style = nullptr;
		ink = 0;
	}

	// 2 param constructor
	Pen::Pen(const char* stylez, int inkz) {
		
		if (stylez == nullptr || stylez[0] == '\0') {
			style = nullptr;
			ink = 0;
		}
		else {
			// dynamically allocating style
			style = new char[strlen(stylez) + 1];
			strcpy(style, stylez);

			if (inkz < 1 || inkz > 50) {
				ink = INK_MAX;
			}
			else {
				ink = inkz;
			}
		}
	}

	// writing a for loop to determine how many non-spaces were input 
	void Pen::write(const char* writing) {
		if (ink > 0) {
			cout << "Writing out the following: " << writing << " with a Pen!" << endl;
			for (unsigned int i = 0; i < strlen(writing); i++) {
				if (writing[i] != ' ') {
					ink = ink - 2; 
				}
			}
			if (ink < 0) {
				ink = 0;
			}

		}
		else {
				cout << "We can't write without ink!" << endl;
		}
	}

	// refilling pen function
	void Pen::refill(int gimmemoar) {
		ink = ink + gimmemoar;
		if (ink > INK_MAX) {
			ink = INK_MAX;
		}
		cout << "Refilling the pen with ink" <<endl;

	}

	// checks to see if there is ink in pen
	bool Pen::filled() const {
		
		if (ink > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// display function
	ostream& Pen::display(ostream& os) const {

		if (style == nullptr && ink == 0) {
			os << "This is an empty Pen" << endl;
		}
		else {
			os << "Pen Details" << endl;
			os << "Style: " << style << endl;
			os << "Ink Remaining: " << ink << endl;
		}
		return os;
	}

	Pen::~Pen() {
		delete[] style;
	}




}