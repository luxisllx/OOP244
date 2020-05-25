// Name: Liang Luxi
// Student Number: 216839188
// Course: OOP244-NEE
// September 16, 2019
// Prototypes for Contact functions

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

namespace sdds {

	struct Contact {
		char name[31];
		long long phoneNumber;
	};

	void getContact(Contact* C);

	void printContact(const Contact* C);

	void getName(char* name);

	bool nameInContact(const Contact* C, const char* nameSubStr);

	void printContacts(const Contact* C, int num);

}
#endif
