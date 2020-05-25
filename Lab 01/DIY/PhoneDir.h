// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Prototypes for PhoneDir Functions

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_PHONEDIR_H
#define SDDS_PHONEDIR_H
#include "Contact.h"
#define MAX_REC_NO 100

namespace sdds {

	int menu();


	int compare(const Contact* A, const Contact* B);
	
	void phoneDir(const char* title, const char* filename);

}

#endif