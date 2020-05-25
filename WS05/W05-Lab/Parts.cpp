#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Parts.h"


using namespace std;

namespace sdds {

	Arms::Arms() {
		force = 0;
	}

	Arms::Arms(int minforce){
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

	Arms& Arms::operator+=(int zforce){
		force += zforce;
		if (force < 1) {
			force = 0;
		}
		return *this;
	}










}