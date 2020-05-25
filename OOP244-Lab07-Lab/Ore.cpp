// Luxi Liang
// OOP244 Lab07
// 11/11/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Ore.h"

namespace sdds {

	//default constructor
	//setting objects to safe empty states
	Ore::Ore() {
		weight = 0.00;
		purity = 0;
		strcpy(classification, "Unknown");
	}

	// 3 argument constructor
	// setting parameters
	Ore::Ore(double weightz, int purityz, const char* classificationz) {

		if (weightz < 1) {
			weight = DEFAULT_WEIGHT;
		}
		else {
			weight = weightz;
		}

		if (purityz < 1 || purityz > 100) {
			purity = DEFAULT_PURITY;
		}
		else {
			purity = purityz;
		}

			if (strlen(classificationz) > CLASS_LEN) {
				strncpy(classification, classificationz, CLASS_LEN + 1);
			}
			else {
				strcpy(classification, classificationz);
			}
		
	}

	bool Ore::refine() {
		if (purity == 100) {
			cout << "Can no longer be refined" << endl;
			return false;
		}
		else {
			weight = weight - 20;
			purity = purity + 10;

			if (purity > 100) {
				purity = 100;
			}
			return true;
		}
	}

	//display function
	// directing outcome to os parameter

	ostream& Ore::display(ostream& os) const {
		//if (weight == 0.00 || purity == 0 || !strcmp(classification, "Unknown")) {
		if (weight == 0.00 || purity == 0 ) {
			os << "This ore is imaginary" << endl;
		}
		else {
			os << std::fixed << std::setprecision(2) << "Weight: " << weight << endl;
			os << "Purity: " << purity << endl; 
			os << "Classification: " << classification << endl;
		}
		return os;
	}

	istream& Ore::input(istream& is) {

		double tempWeight;
		cout << "Enter a value for this ore's weight: ";
		is >> tempWeight;

		int tempPurity;
		cout << "Enter a value for this ore's purity: ";
		is >> tempPurity;

		char tempClass[CLASS_LEN + 1];
		cout << "Enter a classification for the ore (MAX 30 chars): ";
		is.ignore();
		//tempClass is a string, so the ending needs to have a terminator 
		is.getline(tempClass, CLASS_LEN, '\n');

		//calling the 3-arg constructor

		if (tempWeight < 1) {
			weight = DEFAULT_WEIGHT;
		}
		else {
			weight = tempWeight;
		}

		if (tempPurity < 1 || tempPurity > 100) {
			purity = DEFAULT_PURITY;
		}
		else {
			purity = tempPurity;
		}

		if (strlen(tempClass) > CLASS_LEN) {
			strncpy(classification, tempClass, CLASS_LEN + 1);
		}
		else {
			strcpy(classification, tempClass);
		}
		return is;
		
	}
	ostream& operator<<(ostream& os, const Ore& ore) {
		os << "Ore" << endl;
		ore.display(os);
		return os;

	}
	istream& operator>>(istream& os, Ore& ore) {
		ore.input(os);
		return os;
	}







}