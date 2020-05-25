// Name: Luxi Liang
// Number: 165936188
// Date: October 13, 2019
// Lab 05 DIY

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "RobotSquad.h"
#include "Robot.h"
#include "Parts.h"

using namespace std;

namespace sdds {



	RobotSquad::RobotSquad() {
		strcpy(name, "No Name");
		roster = nullptr;
		count = 0;

	}

	RobotSquad& RobotSquad::operator+=(Robot newRobot) {

		// Create new variable oldroster to prepare for shallow copying
		Robot* oldroster;
		oldroster = roster;
		// Dynamically allocate memory for new Robot
		roster = new Robot[count + 1];
		// Add my new Robots into the empty Roster
		roster[count] = newRobot;
		// Use a for loop to shallow copy over the number of Robots
		for (int i = 0; i < count; i++) {
			roster[i] = oldroster[i];
		}
		// Delete oldroster
		delete[] oldroster;
		// Update my count
		count = count + 1;
		return *this;
	}

	RobotSquad& RobotSquad::operator--(){

		// Check to see if roster is reduced to zero
		if (count == 1) {
			delete[] roster;
			roster = nullptr;
			count = 0;
			strcpy(name, "No Name");
			return *this;
		}
		if (count == 0) {
			cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
			return *this;
		}
		// Create new variable oldroster to prepare for shallow copying
		Robot* oldroster;
		oldroster = roster;
		// Dynamically allocate memory for removing Robot
		roster = new Robot[count - 1];
		// Use a for loop to shallow copy over the number of Robots
		for (int i = 0; i < count-1; i++) {
			roster[i] = oldroster[i];
		}
		// Delete oldroster
		delete[] oldroster;
		// Update my count
		count = count - 1;	
		return *this;
	}
	// diplaying robot info 
	ostream& RobotSquad::display() const {
		if (count == 0) {
			cout << "Squad **" << name << "** has no members" << endl;
			return cout;
		}
		else {
			cout << "***Squad Summary***" << endl;
			cout << "Name: " << name << endl;
			cout << "Roster Count: " << count << endl;
			cout << "Roster:" << endl;
			
			for (int i = 0; i < count; i++) {
				roster[i].display();

			}
		}
		return cout;

	}
	Robot* RobotSquad::getRoster() const {
		return roster;
	}

	RobotSquad::RobotSquad(const char* overloaded) {
		strcpy(name, overloaded);
		roster = nullptr;
		count = 0;

	}
	// Deallocate roster if it's not nullptr
	RobotSquad::~RobotSquad() {
		if (roster != nullptr) {
			delete[] roster;
		}
	}








}