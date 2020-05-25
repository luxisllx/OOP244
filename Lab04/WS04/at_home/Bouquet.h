// COURSE: OOP244 LAB 04 - at home
// NAME: LUXI LIANG
// STUDENT #: 165936188
// DATE: 10-04-2019

#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H
#include <iostream>
#include <iomanip>
#include <cstring>


using namespace std;

namespace sdds {

	const int MESS_MAX_LEN = 30;
	const int MAX_FLOWERS = 3;

	class Bouquet {

		double b_price;
		char* b_message;
		Flower* b_flowers;
		int b_flowerCount;

	public:

		Bouquet();
		Bouquet(const Flower* flowers, int flowerNumber = MAX_FLOWERS, const char* message = "Congratulations");
		~Bouquet();
		const char* message() const;
		double price() const;
		bool isEmpty()const;
		void setEmpty();
		void setMessage(const char* prompt);
		void discardBouquet();
		void arrangeBouquet();
		ostream& display() const;



	};















}
#endif