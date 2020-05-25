// COURSE: OOP244 LAB 04- at home
// NAME: LUXI LIANG
// STUDENT #: 165936188
// DATE: 10-05-2019

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flower.h"
#include "utils.h"
#include "Bouquet.h"


using namespace std;

namespace sdds {

	Bouquet::Bouquet() {
		b_price = 0.0;
		b_message = nullptr;
		b_flowers = nullptr;
		b_flowerCount = 0;
	}

	// Three argument constructor
	Bouquet::Bouquet(const Flower* flowers, int flowerNumber, const char* message) {

		if (flowers == nullptr) {
			b_price = 0.0;
			b_message = nullptr;
			b_flowers = nullptr;
			b_flowerCount = 0;
		}
		else {
			if (flowerNumber < MAX_FLOWERS) {
				b_flowerCount = flowerNumber;
			}
			else {
				b_flowerCount = MAX_FLOWERS;
			}

			b_flowers = new Flower[b_flowerCount];
			b_price = 0.0;
			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].setName(flowers[i].name(), strlen(flowers[i].name()));

				b_flowers[i].setColour(flowers[i].colour(), strlen(flowers[i].colour()));
				
				b_flowers[i].setPrice(flowers[i].price());
				
				b_price += flowers[i].price();
			}

			b_message = new char[strlen(message) + 1];
			strcpy(b_message, message);

		}

	}
	// Destructor 
	Bouquet::~Bouquet(){

		if (isEmpty()) {				
			cout << "An unknown bouquet has departed..." << endl;
		}
		else {
			cout << "A bouquet has departed with the following flowers..." << endl;				
			delete[] b_flowers;
			delete[] b_message;
		}
			
	}
	
	const char* Bouquet::message() const
	{
		return b_message;
	}

	double Bouquet::price() const
	{
		return b_price;
	}
	
	bool Bouquet::isEmpty() const
	{
		if (b_flowers == nullptr) {
			return true;
		}
		else
		{
			return false;
		}
		
	}

	// Set to safe empty state
	void Bouquet::setEmpty()
	{
		if (b_flowers!=nullptr) {
			delete[] b_flowers;
			
		}
		if(b_message!=nullptr){
			delete[] b_message;
		
		}
		
		b_price = 0.0;
		b_message = nullptr;
		b_flowers = nullptr;
		b_flowerCount = 0;


	}
	// User inputs message 
	void sdds::Bouquet::setMessage(const char* prompt)
	{
		cout << prompt;
		char message[MESS_MAX_LEN + 1];
		read(message, MESS_MAX_LEN, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");

		if (b_message != nullptr) {
			delete[] b_message;
		}

		b_message = new char[strlen(message)+1];

		strcpy(b_message, message);
	}
	// Printing a message and setting to safe empty state
	void sdds::Bouquet::discardBouquet()
	{
		cout << "Discarding the current bouquet..." << endl;
		setEmpty();
	}

	// Checks if the bouquet is empty or not
	// If not empty, ask user to discard or not
	// Regardless if empty, ask user to enter bouquet
	void sdds::Bouquet::arrangeBouquet()
	{
		cout << "Arranging a new bouquet..." << endl;
		if (!isEmpty()) {
			cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
			
			char c;
			//char newline;

			c = getchar();
			//newline = getchar();
			while ((getchar()) != '\n');

			while (c != 'Y' && c != 'N') {
				
				cout << "The decision is either Y or N... Try again: " << c;
				c = getchar();
				//newline = getchar();
				while ((getchar()) != '\n');
			}
			

			if (c=='Y') {
				discardBouquet();
			}
			else
			{
				cout <<"No new arrangement performed..." << endl;
				return;
			}

		}

		cout << "Enter the number of flowers in this bouquet (Valid: 1-"<< MAX_FLOWERS <<")... : ";

		int val;
		
		read(val, 1, 3, "The valid range is 1-3... Try again: ");

		b_flowerCount = val;
		b_flowers = new Flower[b_flowerCount];
		for (int i = 0; i < b_flowerCount; i++) {
			b_flowers[i].setFlower();
		}

		b_price = 0.0;
		for (int i = 0; i < b_flowerCount; i++) {
			b_price += b_flowers[i].price();
		}

		cout << "A bouquet has been arranged..." << endl;
		setMessage("Enter a message to send with the bouquet...: ");

		
	}
	// Display all the information, including total flower and price 
	ostream& sdds::Bouquet::display() const
	{
		if (isEmpty()) {
			cout << "This is an empty bouquet..." << endl;
		}
		else {
			cout << std::fixed << std::setprecision(2) << "This bouquet worth " << b_price << " has the following flowers..." << endl;
			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].display();
			}
			cout << "with a message of: "<<b_message<<endl;
		}
		//cout << endl;
		return cout;
	}

}

// Roses are Red
// Violets are Blue
// OOP is hard 
// My heart is now scarred :(
