#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H
#include <iostream>



using namespace std;

namespace sdds {

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

}















#endif