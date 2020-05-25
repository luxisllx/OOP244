// Luxi Liang
// OOP244 Home06
// 11/09/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Figurine.h"

namespace sdds {

	// default constructor. Setting objects to safe empty state
	Figurine::Figurine() {
		name[0] = '\0';
		pose = nullptr;
		price = 0.00;
		copy = false;
	}
	// 3 argument constructor
	Figurine::Figurine(const char* namez, const char* posez, double pricez) {
	 
		if (namez == nullptr || namez[0] == '\0' || posez == nullptr || posez[0] == '\0') {
			name[0] = '\0';
			pose = nullptr;

		}
		else {
			if (strlen(namez) > MAX_NAME_LEN) {
				strncpy(name, namez, MAX_NAME_LEN + 1);
			}
			else {
				strcpy(name, namez);

			}
			pose = new char[strlen(posez) + 1];
			strcpy(pose, posez);
			if (pricez < 1) {
				price = DEFAULT_PRICE;
			}
			else {
				price = pricez;
			}
		}
		copy = false;
	}
	// copy constructor
	Figurine::Figurine(const Figurine& Pikachu) {
		strcpy(name, Pikachu.name);
		price = Pikachu.price;

		if (Pikachu.pose == nullptr || Pikachu.pose[0] == '\0') {
			pose = nullptr;
		}
		else {

			pose = new char[strlen(Pikachu.pose) + 1];
			strcpy(pose, Pikachu.pose);
		}
		copy = true;
	}

	Figurine& Figurine::operator=(const Figurine& Mewtwo) {
		// if address of parameter is same as the current object, return current object
		if (&Mewtwo == this) {
			return *this;
		}
		else {
			delete[] pose;
			strcpy(name, Mewtwo.name);
			price = Mewtwo.price;
			if (Mewtwo.pose != nullptr && Mewtwo.pose[0] != '\0') {
				pose = new char[strlen(Mewtwo.pose) + 1];
				strcpy(pose, Mewtwo.pose);
			}
			copy = true;
			return *this;
		}
			

	}
	//  function to set the name of the figurine
	// copying the input name into the current object 
	void Figurine::setName(const char* Pichu) {
		strcpy(name, Pichu);
	}
	// function to set the pose of the figurine 
	// copying the input pose into the current object
	void Figurine::setPose(const char* Thundershock) {
		delete[] pose;
		pose = new char[strlen(Thundershock) + 1];
		strcpy(pose, Thundershock);
	}
	void Figurine::setPrice(double Pokecoin) {
		if (price < 1) {
			price = DEFAULT_PRICE;
		}
		else {
			price = Pokecoin;
		}
	}
	//display function
	ostream& Figurine::display() const {
		if (name == nullptr || name[0] == '\0' || pose == nullptr || pose[0] == '\0') {
			cout << "This Figurine has not yet been sculpted" << endl;
			if (copy == true) {
				cout << "This is a replica of emptiness" << endl;
			}
		}

		else {
			cout << "Figurine Details" << endl;
			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << std::fixed << std::setprecision(2) << "Price: " << price << endl;
			if (copy == true) {
				cout << "This is a replica" << endl;
			}
		}
		return cout;
	}
	// if name is a nullpointer or its empty, return true. otherwise, return false
	Figurine::operator bool() const {
		if (name == nullptr || name[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}
	bool Figurine::isCopy() const {
		return copy;
	}

	// creating a function that gets the name of the figurine
	// need to dynamically allocate memory in order to return a char array
	char* Figurine::getName() const{
		char* newname;
		newname = new char [strlen(name) + 1];
		strcpy(newname, name);
		return newname;
	}
	//creating a funnction that gets the pose of the figurine
	char* Figurine::getPose() const{
		return pose;
	}

	//creating a function that gets the price of the figurine
	double Figurine::getprice() const {
		return price;
	}

	// returns true if all conditions are same between the two figurines
	// and neither figurines are copy of each other
	bool operator==(const Figurine& Snorlax, const Figurine& Munchlax) {
		
		// creating two variables to represent the names of figurine one and two
		char* newname = Snorlax.getName();
		char* mininame = Munchlax.getName();
		if (strcmp(newname, mininame) == 0 && (strcmp(Snorlax.getPose(), Munchlax.getPose()) == 0 && Snorlax.getprice() == Munchlax.getprice() && !Snorlax.isCopy() && !Munchlax.isCopy())) {
			//deleting the variables of figurine one and two to avoid memory leak
			delete[] newname;
			delete[] mininame;
			return true;
		
		}
		
		else {
			return false;
		}
		}
	
	// deconstructor
	Figurine::~Figurine() {
		delete[] pose;
	}


}





