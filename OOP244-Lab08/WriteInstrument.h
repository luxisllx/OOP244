// Luxi Liang
// OOP244 Lab08
// 11/20/2019

#ifndef SDDS_INSTRUMENT_H
#define SDDS_INSTRUMENT_H
#include <iostream>

using namespace std;

namespace sdds {

	class WriteInstrument {

	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char*) = 0;
		virtual void refill(int) = 0;
		virtual bool filled() const = 0;
		virtual ostream& display(ostream& os) const = 0;

	};


}
#endif
