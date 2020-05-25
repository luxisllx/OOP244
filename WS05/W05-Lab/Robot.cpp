#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Parts.h"
#include "Robot.h"

using namespace std;

namespace sdds {
	
	Robot::Robot():arms(){
		nickname[0] = '\0';
		durability = 0;	
	}


	Robot::Robot(const char* x_nickname, int x_force, int x_durability):arms(x_force) {
		
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
	ostream& Robot::display() const{
		if (nickname[0] == '\0'  || durability == 0) {
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: "<< nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;

			
		}
		return cout;

	}

	Robot::operator bool() const {
		if (nickname[0] == '\0' || durability == 0) {
			return true;
		}
		return false;


	}








}