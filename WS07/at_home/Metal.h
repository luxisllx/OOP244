// Luxi Liang
// OOP244 Lab07-Home
// 11/13/2019

#ifndef SDDS_METAL_H
#define SDDS_METAL_H
#include <iostream>
#include "Ore.h"

using namespace std;

namespace sdds {

	const double DEFAULT_MOHS = 2.5;
	const int NAME_LEN = 10;

	class Metal : public Ore {
		
		char* name;
		double mohs;

	public:

		Metal();
		Metal(double, int, const char*, const char*, double);
		void refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
		~Metal();
		
	};
	ostream& operator<<(ostream& os, const Metal& met);
	istream& operator>>(istream& os, Metal& met);











}
#endif