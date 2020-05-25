#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Parts.h"
#include "Robot.h"

using namespace std;

namespace sdds {

	Robot::Robot() :arms(), legs() {
		nickname[0] = '\0';
		durability = 0;
	}


	Robot::Robot(const char* x_nickname, int x_force, int x_speed, int x_durability) :arms(x_force), legs(x_speed) {

		// if input = nullptr or empty string, then set object member nickname to nullptr
		if (x_nickname == nullptr || strcmp(x_nickname, "") == 0) {

			nickname[0] = '\0';
			durability = 0;
		}
		else {
			if (strlen(x_nickname) > NICK_MAX_LEN) {
				strncpy(nickname, x_nickname, NICK_MAX_LEN + 1);
			}
			else {
				// copying string: destination nickname, source x_nickname
				strcpy(nickname, x_nickname);
			}
			if (x_durability < 1) {
				durability = 100;
			}
			else {
				durability = x_durability;
			}
		}


	}
	ostream& Robot::display() const {
		if (nickname[0] == '\0' || durability == 0)  {
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Leg Speed: " << legs.getSpeed() << endl;
		}
		return cout;

	}

	Robot::operator bool() const {
		if (nickname[0] == '\0' || durability == 0) {
			return true;
		}
		return false;
	}
	// Return arms not "this" because this is Robot.cpp, not arms.cpp
	// Returning a copy of Arms (current)
	Arms Robot::getArms() const {
		return arms;
	}

	// Returning a copy of Legs (current)
	Legs Robot::getLegs() const {
		return legs;
	}

	// If durability is less than 1, set it to zero
	Robot& Robot::operator-=(int zdurability) {
		durability -= zdurability;
		if (durability < 1) {
			durability = 0;
		}
		return *this;	// returning actual object
	}

	void box(Robot& naruto, Robot& sasuke) {
		cout << "Attempting to begin a Robot boxing match" << endl;

		
		if (naruto.durability != 0 && naruto.nickname[0] != '\0' && sasuke.durability != 0 && sasuke.nickname[0] != '\0') {
			cout << "Both participants are operational... beginning the bout" << endl;
		}
		else {
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
			return;
		}
		// while both robots are still functional
		while (naruto.durability != 0 && sasuke.durability != 0) {
			// if naruto is faster, he gets to attack first
			// sasuke's durability = his durability - naruto's force
			if (naruto.getLegs().getSpeed() > sasuke.getLegs().getSpeed()) {
				sasuke -= naruto.getArms().getForce();	// ?? why do we delete the robot&
				if (sasuke.durability != 0) {
					naruto -= sasuke.getArms().getForce();
				}
			}

			else {
				naruto -= sasuke.getArms().getForce();
				if (naruto.durability != 0) {
						sasuke -= naruto.getArms().getForce();
				}
			}
		}
		// if either robot's durability is zero then we have a winner.
		// determining winner based on which robot has zero durability.
		if (naruto.durability == 0 || sasuke.durability == 0) {
			cout << "The bout has concluded... the winner is: " << endl;
			if (naruto.durability != 0 && sasuke.durability == 0) {
				naruto.display();
			}
			else {
				sasuke.display();
			}
		}
		
	}
	 
}

