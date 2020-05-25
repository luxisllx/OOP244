#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "ReportUtils.h"

using namespace std;

namespace sdds {

	void flushKeyboard(){

		char newline;
		do {
			newline = cin.get();
			if (newline == '\n') {
				break;
			}
		} while (1);
	}
}

