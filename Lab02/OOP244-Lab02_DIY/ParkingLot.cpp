#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ParkingLot.h"
#include "ParkingSpot.h"
#include "utils.h"

using namespace std;

namespace sdds {

	//Function that sets the value of parking spots
	void setEmpty(ParkingLot& empty) {

		empty.number = 0;
		empty.slots = NULL;
	}
	//Function that determines if spot is empty
	bool isEmpty(const ParkingLot& emptier) {

		if (emptier.slots == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	//Function that determines available number of spots
	void openParking(ParkingLot& open, int noOfSpots) {

		open.number = noOfSpots;
		open.slots = new ParkingSpot[noOfSpots];

		for (int i =0; i < noOfSpots; i++) {
			setEmpty(open.slots[i]);
		}
	}
	//Function that determines which slots is assigned for parking
	int parkCar(ParkingLot& parking) {

		for (int i = 0; i < parking.number; i++) {

			if (isEmpty(parking.slots[i])) {

				parkCar(parking.slots[i]);

				return i;
			}
		}
		return -1;

	}
	//Function that determines that slot of not empty. If empty, will return false
	bool returnCar(ParkingLot& returni, int spotNo) {

		if (spotNo >= 0 && spotNo < returni.number && !isEmpty(returni.slots[spotNo])) {

			cout << "Returning ";
			print(returni.slots[spotNo]);
			freeSpot(returni.slots[spotNo]);
			return true;
		}
		else
			return false;
	}
	//Deletes dynamic array parking spots 
	void closeParking(ParkingLot& closed) {
		for (int i = 0; i < closed.number; i++) {
			if (!isEmpty(closed.slots[i]))
				returnCar(closed, i);
		} 
		delete[] closed.slots;
		setEmpty(closed);

	}

}