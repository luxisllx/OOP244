#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Parts.h"


using namespace std;

namespace sdds {

	Legs::Legs() {
		speed = 0;
	}
	 // if input for leg speed is less than 1, set speed to default
	Legs::Legs(int minspeed) {
		if (minspeed < 1) {
			speed = MIN_SPEED;
		}
		else {
			speed = minspeed;
		}
	}

	int Legs::getSpeed() const {
		return speed;
	}

	Legs& Legs::operator-=(int xspeed){
		speed -= xspeed;
		if (speed < 1) {
			speed = 0;
		}
		return *this;
	}


	Arms::Arms() {
		force = 0;
	}

	Arms::Arms(int minforce) {
		if (minforce < 1) {
			force = MIN_FORCE;
		}
		else {
			force = minforce;
		}
	}

	int Arms::getForce() const {
		return force;
	}

	// increment arms force by 10
	Arms& Arms::operator++() {
		force = force + 10;
		return *this; // returning actual object by reference (???)
	}



	Arms Arms::operator++(int xforce) {
		//creating a new object called secondArm, type Arms, calling a one argument constructor
		// this force is the current object's force
		Arms secondArm(force);
		force = force + 10;
		return secondArm;
	}

	Arms& Arms::operator+=(int zforce) {
		force += zforce;
		if (force < 1) {
			force = 0;
		}
		return *this;
	}

	// returns true if leg1 is faster than leg2
	bool operator>(const Legs& leg1, const Legs& leg2) {
		return leg1.getSpeed() > leg2.getSpeed();

	}

	// returns true if leg1 is slower than leg2
	bool operator<(const Legs& leg1, const Legs& leg2) {
		return leg1.getSpeed() < leg2.getSpeed();
	}
	// return true if arm1 is stronger than arm2
	bool operator>(const Arms& arm1, const Arms& arm2) {
		return arm1.getForce() > arm2.getForce();
	}

	// return true if arm1 is weaker than arm2
	bool operator<(const Arms& arm1, const Arms& arm2) {
		return arm1.getForce() < arm2.getForce();
	}









}
