// Luxi Liang
// OOP244 Lab07
// 11/13/2019

#ifndef SDDS_ORE_H
#define SDDS_ORE_H
#include <iostream>

using namespace std;

namespace sdds {

	const double DEFAULT_WEIGHT = 300.50;
	const int DEFAULT_PURITY = 20;
	const int CLASS_LEN = 30;

	class Ore {


		double weight;
		int purity;
		char classification[CLASS_LEN + 1];

	public:
		Ore();
		Ore(double weightz, int purityz, const char* classificationz = "Unknown");
		bool refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
	};
	//helper
	ostream& operator<<(ostream& os, const Ore& ore);
	istream& operator>>(istream& os, Ore& ore);
}

#endif
