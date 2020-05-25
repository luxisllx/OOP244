// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019

#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__
#include <iostream>
#include <cstring>
#include <limits>
#include "ReadWriteable.h"

using namespace std;

namespace sdds {
	const int SDDS_CONSOLE = 32;
	const int SDDS_FILE = 64;


	class PubRecord :public ReadWriteable {
		char* m_name;
		int m_shelfNo;
		int m_mediaType;

	public:

		virtual char recID()const = 0;
		PubRecord();
		PubRecord(const PubRecord&);
		~PubRecord();
		PubRecord& operator= (const PubRecord&);
		void mediaType(int);
		int mediaType()const;
		int shelfNo()const;
		void readShelfNo();
		bool operator==(char)const;
		bool operator==(const char*)const;
		operator bool()const;

	protected:
		void name(const char*);
		const char* name()const;

	};

}
#endif

