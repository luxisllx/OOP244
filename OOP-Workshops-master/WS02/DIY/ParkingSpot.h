#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PARKINGSPOT_H
#define SDDS_PARKINGSPOT_H
#include <iostream>
#include "utils.h"
#include "ParkingLot.h"


namespace sdds {

// Prototypes for ParkingSpot

	struct ParkingSpot {
		char license[9];
		char* makeModel;
	};
	void setEmpty(ParkingSpot&);
	bool isEmpty(const ParkingSpot&);
	void freeSpot(ParkingSpot&);
	void print(const ParkingSpot&);
	void parkCar(ParkingSpot&);


}
#endif