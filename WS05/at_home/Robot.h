#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include <iostream>
#include "Parts.h"

using namespace std;

namespace sdds {

	const int NICK_MAX_LEN = 10;


	class Robot {


		char nickname[NICK_MAX_LEN + 1];
		int durability;
		Arms arms;
		Legs legs;

	public:
		Robot();
		Robot(const char*, int, int, int);
		ostream& display() const;

		operator bool() const;
		Arms getArms() const;
		Legs getLegs() const;
		Robot& operator-=(int);
		friend void box(Robot&, Robot&);

	};

	void box(Robot&, Robot&);
}
#endif

