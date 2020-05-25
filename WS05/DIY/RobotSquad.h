#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H
#include <iostream>
#include "Robot.h"
#include "Parts.h"

using namespace std;

namespace sdds {

	class RobotSquad {
	
		char name[10];
		Robot* roster;
		int count;
		
	public:
		RobotSquad();
		RobotSquad(const char*);
		RobotSquad& operator+=(Robot);
		RobotSquad& operator--();
		ostream& display() const;
		Robot* getRoster() const;
		~RobotSquad();

	};













}
#endif
