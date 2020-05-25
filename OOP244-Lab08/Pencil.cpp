// Luxi Liang
// OOP244 Lab08
// 11/20/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Pencil.h"

namespace sdds {

	Pencil::Pencil() {
		HB_scale[0] = '\0';
		graphite = 0;
	}

	// checking to see if scale and amount have input or empty
	Pencil::Pencil(const char* scale, int amount) {
		
		if (scale == nullptr || scale[0] == '\0') {
			HB_scale[0] = '\0';
			graphite = 0;
		}
		else {
			strncpy(HB_scale, scale, HB_MAX + 1);
			if (amount < 1 || amount > 100) {
				graphite = GRAPHITE_MAX;
			}
			else {
				graphite = amount;
			}
		}
	}

	void Pencil::write(const char* text) {

		// single quotes is char, double is string
		// using a for loop to determine how many spaces were entered
		// p.s graphite shouldn't go down with spaces?? Should go down with writing, no??
		if (graphite != 0) {
			cout << "Writing out the following: " << text << " with a Pencil!" << endl;
			for (unsigned int i = 0; i < strlen(text); i++) {
				if (text[i] == ' ') {
					graphite = graphite - 5;
				}
			}
			if (graphite < 0) {
				graphite = 0;
			}
		}
		else {
			cout << "We can't write without graphite!" << endl;
		}

	}
	// refilling graphite
	void Pencil::refill(int gimmemore) {

		graphite = graphite + gimmemore;
		if (graphite > GRAPHITE_MAX) {
			graphite = GRAPHITE_MAX;
		}
		cout << "Refilling the pencil with graphite" << endl;

	}
	// if there is graphite, return true
	// otherwise, return false
	bool Pencil::filled() const {
		if (graphite > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	// display function
	ostream& Pencil::display(ostream& os) const {
		if (HB_scale[0] == '\0' && graphite == 0) {
			os << "This is an empty Pencil" << endl;
		}
		else {
			os << "Pencil Details" << endl;
			os << "HB Value: " << HB_scale << endl;
			os << "Graphite Remaining: " << graphite << endl;

		}
		return os;
	}

	







}