// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019

#ifndef SDDS_READWRITEABLE_H__
#define SDDS_READWRITEABLE_H__
#include <iostream>

using namespace std;

namespace sdds {
	class ReadWriteable {
	public:

		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout)const  = 0;

		friend ostream& operator<<(ostream& output, const ReadWriteable& D);

		friend istream& operator>>(istream& input, ReadWriteable& D);

	};

}
#endif

