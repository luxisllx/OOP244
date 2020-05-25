// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Organized all prototypes related to File function



#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "Contact.h"
#define MAX_REC_NO 100

namespace sdds
{

	bool readContact(Contact* C, FILE* fptr);

	void writeContact(FILE* fptr, const Contact* C);

	int readContacts(Contact* contacts, const char* filename);

	void writeContacts(Contact* contacts, int cntno, const char* filename);

}
#endif 
