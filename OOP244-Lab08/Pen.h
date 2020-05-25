// OOP244 Lab08
// 11/20/2019

#ifndef SDDS_PEN_H
#define SDDS_PEN_H
#include <iostream>
#include "WriteInstrument.h"

using namespace std;

namespace sdds {

	const int INK_MAX = 50;

	class Pen : public WriteInstrument {

		char* style;
		int ink;

	public:
		Pen();
		Pen(const char*, int);
		virtual void write(const char*);
		virtual void refill(int);
		virtual bool filled() const;
		virtual ostream& display(ostream& os) const;
		~Pen();
	};


}
#endif