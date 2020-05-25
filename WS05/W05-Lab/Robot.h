#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include <iostream>
#include "Parts.h"
 
using namespace std;

namespace sdds {

	const int NICK_MAX_LEN = 10;

	class Robot {

		// does the professor mean it's not dynamically allocated or it's an actual static char
		char nickname[NICK_MAX_LEN + 1];
		int durability;
		Arms arms;

	public:
		Robot();
		Robot(const char*, int, int);
		ostream& display() const;

		operator bool() const;

	};
}
#endif
 