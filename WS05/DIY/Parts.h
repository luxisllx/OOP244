#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H
#include <iostream>

using namespace std;

namespace sdds {

	//minimum speed for legs
	const int MIN_SPEED = 25;
	// minimum force for arms 
	const int MIN_FORCE = 50;

	class Arms {

		int force;

	public:

		Arms();
		Arms(int);
		int getForce() const;

		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);
	};

	class Legs {

		int speed;

	public:
		Legs();
		Legs(int);
		int getSpeed() const;
		Legs& operator-=(int);

	};

	bool operator>(const Arms&, const Arms&);
	bool operator<(const Arms&, const Arms&);

	bool operator>(const Legs&, const Legs&);
	bool operator<(const Legs&, const Legs&);
}

#endif
