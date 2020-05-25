#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ParkingSpot.h"
#include "utils.h"
using namespace std;

namespace sdds {

	//Sets value of license and vehicle information
	void setEmpty(ParkingSpot& carInfo) {

		carInfo.license[0] = '\0';
		carInfo.makeModel = NULL;

	}

	// Returns true if parking spot is empty
	bool isEmpty(const ParkingSpot& empty) {

		if (empty.makeModel == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	// Frees up the parking spot and deletes previous vehicle information
	void freeSpot(ParkingSpot& deleted) {

		delete[] deleted.makeModel;
		setEmpty(deleted);
	}

	// Displays the vehicle information
	void print(const ParkingSpot& display) {

		cout << display.makeModel <<", plate number: "<< display.license << endl;
	}

	// Reads the vehicle information from user input
	// Displays errors message if goes out of range limits
	void parkCar(ParkingSpot& park) {

		char make[61];
		char plate[9];
		cout << "Make and Model: ";

		read(make, 60, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
		cout << "License Plate: ";

		read(plate, 8, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");

		park.makeModel = new char[strlen(make) + 1];
		strcpy(park.makeModel, make);

		strcpy(park.license, plate);
	}

}