// COURSE: OOP244 LAB 04
// NAME: LUXI LIANG
// STUDENT #: 165936188
// DATE: 10-02-2019

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flower.h"
#include "utils.h"


using namespace std;

namespace sdds {

	Flower::Flower() {
		f_name = NULL;
		f_colour = NULL;
		f_price = 0.0;
	}

	Flower::Flower(const char* name, const char* color, double price) {
		// using strcmp because we are comparing strings. Cannot use == when dealing with strings
		if (name == NULL || strcmp(name, "")==0 || color == NULL || strcmp(color, "")==0 || price <= 0){		
			
			f_name = NULL;
			f_colour = NULL;
			f_price = 0.0;
	
		}
		else {
			f_name = new char[strlen(name) +1];		//dynamically allocating memeory for name
			strcpy(f_name, name);					//destination and then source

			
			f_colour = new char[strlen(color) + 1];		// dynamically allocating memory for colour
			strcpy(f_colour, color);					// copy value of color into f_colour

			f_price = price;

		}


	}
	Flower::~Flower() {
	
		if (isEmpty()) {
			cout << "An unknown flower has departed..." << endl;
		}
		else {
			cout << f_colour << " " << f_name << " " << "has departed..." << endl;

			delete[] f_name;					// deallocating 
			delete[] f_colour;
		}
		
			
	}


	const char* Flower::name()const {
		return f_name;
	}
	const char* Flower::colour() const {
		return f_colour;

	}

	double Flower::price() const {
		return f_price;
	}

	bool Flower::isEmpty()const {
		if (f_name == NULL) {
			return true;		// returns true if Flower object is empty
		}
		return false;			// returns false if Flower object is not empty
	}

	void Flower::setEmpty() {
		if (f_name != NULL){			// before setting empty, we need to confirm it's not empty. 
			delete[] f_name;			// if it's not empty, we need to delete dynamic allocated memory
		}

		if (f_colour != NULL) {
			delete[] f_colour;
		}

		f_name = NULL;
		f_colour = NULL;
		f_price = 0.0;
	}

	void Flower::setName(const char* prompt) {
		
		char flowername[26];							// char array = string. setting string to 26 max						

		cout << prompt;
		read(flowername, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");

		if (f_name != NULL) {							// if there is a flower name existing, delete it
			delete[] f_name;
		}

		f_name = new char[strlen(flowername) + 1];		// if there is not an existing flower name, dynamically allocate memory to hold one
		strcpy(f_name, flowername);
	}

	void Flower::setColour(const char* prompt) {

		char flowercolor[16];
	
		cout << prompt ;
		read(flowercolor, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");

		if (f_colour != NULL) {						// if there is existing flower colour, delete it
			delete[] f_colour;						
		}

		f_colour = new char[strlen(flowercolor) + 1];	// if there is not an existing flower color, dynamically allocate memory to hold one
		strcpy(f_colour,flowercolor);
		

	}

	void Flower::setPrice(const char* prompt) {		// this function is setting max and min price for the flower

		double flowerprice;

		cout << prompt;
		bool ok;
		char newline;
		do {
			cin >> flowerprice;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = flowerprice > 0.0;
			}
		} while (!ok && cout << "A flower's price is a non-negative number... Try again: ");
		f_price = flowerprice;
	}
	

	void Flower::setFlower(){			// display prompt


		setName("Beginning the birth of a new flower...\nEnter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");

		cout << "The flower's current details..." << endl;
		display();
	}
	
	ostream& Flower::display() const {			// if name is empty/not empty, display either message

		if (f_name == NULL) {
			cout << "This is an empty flower..." << endl;
		}
		else {
			
			cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;

		}
		return cout;
	}










}
