#ifndef SDDS_MAGAZINE_H__
#define SDDS_MAGAZINE_H__
#include <iostream>
#include <cstring>
#include <limits>
#include "PubRecord.h"

using namespace std;

namespace sdds {

	const int MAX_VOLUME = 99;
	const int MAX_ISSUE_NUMBER = 99;

	class Magazine :public PubRecord
	{
		int m_volume;
		int m_issueNumber;

	public:
		Magazine();
		Magazine(const Magazine&);
		~Magazine();
		Magazine& operator= (const Magazine&);
		bool overdue()const { return false; };

		char recID()const;
		void checkIn();
		void checkOut();

		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;

	};
}
#endif

