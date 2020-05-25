// Luxi Liang
// OOP244 Lab06
// 11/07/2019


#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Figurine.h"

namespace sdds {

	Figurine::Figurine() {
		name[0] = '\0';
		pose = nullptr;
		price = 0.00;
	}

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
	}

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
	}

	void Figurine::setName(const char* Pichu) {
		strcpy(name, Pichu);
	}

	void Figurine::setPose(const char* Thundershock) {
		delete[] pose;
		pose = new char[strlen(Thundershock) + 1];
		strcpy(pose, Thundershock);
	}
	void Figurine::setPrice(double Pokecoin ) {
		if (price < 1) {
			price = DEFAULT_PRICE;
		}
		else {
			price = Pokecoin;
		}
	}
	ostream& Figurine::display() const {
		if (name == nullptr || name[0] == '\0' || pose == nullptr || pose[0] == '\0' ) {
			cout << "This Figurine has not yet been sculpted" << endl;
		}
		else {
			cout << "Figurine Details" << endl;
			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << std::fixed << std::setprecision(2) << "Price: " << price << endl;
		}
		return cout;
	}

	Figurine::operator bool() const {
		if (name == nullptr || name[0] == '\0') {
			return true;
		}
		else {
			return false;
		}
	}
	
		Figurine::~Figurine() {
			delete[] pose;
		}
		
}
	




