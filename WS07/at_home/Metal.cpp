// Luxi Liang
// OOP244 Lab07
// 11/13/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Metal.h"

namespace sdds {

	//default constructor
	Metal::Metal() {
		name = nullptr;
		mohs = 0.00;
	}

	// 5 arg constructor
	// *** calling parent constructor is like this ***
	Metal::Metal(double weightz, int purityz, const char* classificationz, const char* namez, double mohz) :Ore(weightz, purityz, classificationz)
	{


		if (namez == nullptr || namez[0] == '\0') {
			name = nullptr;
		}
		else {
			name = new char[NAME_LEN + 1];
			strcpy(name, namez);
		}

		if (mohz > 0.00) {
			mohs = mohz;
		}
		else {
			mohs = DEFAULT_MOHS;
		}	
	}
	
		void Metal::refine() {

			if (Ore::refine() == true) {
				mohs = mohs + 1;

			}
		}
		// displaying values onto the screen 
		ostream& Metal::display(ostream& os) const{

				if (mohs == 0.00 || name == nullptr) {
					os << "This metal is imaginary" << endl;
				}
				else {
					os << "Name: " << name << endl;
					Ore::display(os);
					os << std::fixed << std::setprecision(2) << "Mohs: " << mohs << endl;
				}
				return os;
		}

		// accepting input for variable values 
		istream& Metal::input(istream& is) {


			char tempArray[NAME_LEN + 1];
			cout << "Enter a value for this metal's name: ";
			is.getline(tempArray, NAME_LEN, '\n');
			delete[]name;

			// allocating new memory for the name
			name = new char[strlen(tempArray) + 1];
			strcpy(name, tempArray);

			// creating temp variable to store mohs value
			double tempMohs;

			cout << "Enter a value for this metal's mohs: ";
			
			is >> tempMohs;
			if (tempMohs <= 0) {
				mohs = DEFAULT_MOHS;
			}
			else {
				mohs = tempMohs;
			}
			is.clear();
			is.ignore(10000, '\n');
			Ore::input(is);
			return is;
		}
		// this function prints to the screen
		// overloads the operator and prints to the screen
		ostream& operator<<(ostream& os, const Metal& met) {

			cout << "Metal" << endl;
			// this function is outside Metal class. 
			// therefore we need a Metal object in order to call the function display() (in this case)
			met.display(os);
			return os;
		}

		// this function overloads the operator and accepts input 
		istream& operator>>(istream& os, Metal& met) {

			
			met.input(os);
			return os;
		}

		Metal::~Metal() {
			delete[] name;

		}




	
}
