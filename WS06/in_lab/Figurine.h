// Luxi Liang
// OOP244 Lab06
// 11/07/2019

#ifndef SDDS_FIGURINE_H
#define SDDS_FIGURINE_H
#include <iostream>

using namespace std;

namespace sdds {

	const int MAX_NAME_LEN = 20;
	const double DEFAULT_PRICE = 25.25;

	class Figurine {

		char name[MAX_NAME_LEN + 1];
		char* pose;
		double price;


	public:

		Figurine();
		Figurine(const char*, const char*, double);
		Figurine(const Figurine&);
		// Figurine& operator=(const Figurine&);
		void setName(const char*);
		void setPose(const char*);
		void setPrice(double);
		ostream& display() const;
		operator bool() const;
		~Figurine();

	};
}
#endif
