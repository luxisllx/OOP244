#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PARKINGLOT_H
#define SDDS_PARKINGLOT_H
#include <iostream>
#include "utils.h"
#include "ParkingSpot.h"

namespace sdds {
// setting prototypes for ParkingLot

	struct ParkingLot {

		int number;
		struct ParkingSpot* slots;
	};
	void setEmpty(ParkingLot&);
	bool isEmpty(const ParkingLot&);
	void openParking(ParkingLot&, int);
	int parkCar(ParkingLot&);
	bool returnCar(ParkingLot&, int);
	void closeParking(ParkingLot&);


}

#endif