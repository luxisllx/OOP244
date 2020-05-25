// COURSE: OOP244 LAB 04
// NAME: LUXI LIANG
// STUDENT #: 165936188
// DATE: 10-04-2019

#ifndef SDDS_FLOWERS_H
#define SDDS_FLOWERS_H
#include <iostream>
#include <cstring>


using namespace std;

namespace sdds {

	const int NAME_MAX_LEN = 25;
	const int COL_MAX_LEN = 15;


	class Flower {

		char* f_name;
		char* f_colour;
		double f_price;

	public:
		Flower();
		Flower(const char*, const char*, double);

		const char* name() const;

		const char* colour() const;

		double price() const;

		bool isEmpty()const;

		void setEmpty();

		void setName(const char* prompt);

		void setColour(const char* prompt);

		void setPrice(const char* prompt);

		void setFlower();

		ostream& display() const;

		void setName(const char* name, int len);

		void setColour(const char* colour, int len);

		void setPrice(double price);



		~Flower();

	};


}
#endif