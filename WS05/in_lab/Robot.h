#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include <iostream>
#include "Parts.h"
 
using namespace std;

namespace sdds {

	const int NICK_MAX_LEN = 10;

	class Robot {

		
		//char nickname[NICK_MAX_LEN + 1];
		char* nickname;
		int durability;
		Arms arms;

	public:
		Robot();
		Robot(const char*, int, int);
		~Robot();
		ostream& display() const;

		operator bool() const;

	};
}
#endif
 