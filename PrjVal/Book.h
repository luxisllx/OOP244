#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include <cstring>
#include <limits>
#include "PubRecord.h"
#include "Date.h"

using namespace std;

namespace sdds {
	class Book :
		public PubRecord
	{
		long long int m_isbn;
		int m_memberId;
		Date m_dueDate;
	public:
		Book();
		~Book();
		Book(const Book&);
		Book& operator= (const Book&);

		char recID()const;
		int memberId()const;
		void checkIn();
		void checkOut();
		bool overdue()const;
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;
	};
}
#endif
