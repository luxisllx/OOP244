// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

namespace sdds {
	Book::Book() {
		m_isbn = 0;
		m_memberId = 0;
	}

	Book::~Book() {

	}

	Book::Book(const Book& b) : PubRecord(b) {
		m_isbn = b.m_isbn;
		m_memberId = 0;
	}

	Book& Book::operator= (const Book& b) {
		PubRecord::operator=(b);
		m_isbn = b.m_isbn;
		m_memberId = 0;

		return *this;
	}

	char Book::recID()const {
		return 'B';
	}

	int Book::memberId()const {
		return m_memberId;
	}

	void Book::checkIn() {
		m_memberId = 0;
		cout << *this;
		cout << " checked in!" << endl;
	}

	void Book::checkOut() {
		cout << "Enter Member id: ";
		int tmp_memberId;
		cin >> tmp_memberId;
		while (cin.fail() || tmp_memberId > 99999 || tmp_memberId < 10000) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Member ID, Enter again: ";
			cin >> tmp_memberId;
		}
		
		m_memberId = tmp_memberId;

		cout <<"Enter return date: ";
		cin >> m_dueDate;

		while (m_dueDate.errCode() != NO_ERROR) {
			cout << m_dueDate.dateStatus()<<"."<<endl;
			cin >> m_dueDate;
		}

		Date today;
		
		while ((m_dueDate - today) < 0) {
			cout << "Please enter a future date."<<endl;
			cout << "Enter return date: ";
			cin >> m_dueDate;
		}

		while ((m_dueDate - today) > 30) {
			cout << "The return date must be earlier than 30 days away from today.";
			cin >> m_dueDate;
		}

	}

	std::istream& Book::read(std::istream& is) {
		//cout << "****Reading book****";
		if (mediaType() == SDDS_CONSOLE) {
			m_memberId = 0;

			cout << "Book Name: ";
			char s[41];
			cin.getline(s, std::streamsize(40) + 1, '\n');
			while (is.fail()) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Book name too long, Enter again: ";
				cin.getline(s, std::streamsize(40) + 1, '\n');
			}

			cout << "ISBN: ";
			long long int tmp_isbn;
			is >> tmp_isbn;

			while (is.fail() || tmp_isbn > 9999999999999 || tmp_isbn < 1000000000000) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid ISBN, Enter again: ";
				is >> tmp_isbn;
			}

			cout << "Shelf Number: ";
			readShelfNo();
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			name(s);
			m_isbn = tmp_isbn;
		}
		else if (mediaType() == SDDS_FILE) {
			char tmp_name[41];
			long long int tmp_isbn;
			int tmp_shelf;
			int tmp_memberId;
			is.getline(tmp_name, 40, '\t');
			//is.ignore();
			//cout << "***" << tmp_name;
			is >> tmp_isbn;
			is.ignore();
			//cout << "****" << tmp_isbn;
			is >> tmp_shelf;
			is.ignore();
			//cout << "****" << tmp_shelf;
			is >> tmp_memberId;
			//cout << "****" << tmp_memberId;
			if (is.fail()) {
				cout << "Book string is invalid" << tmp_name << endl;
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				name(tmp_name);
				m_isbn = tmp_isbn;
				shelfNo(tmp_shelf);
			}

			if (tmp_memberId == 0) {
				is.ignore();
				m_memberId = tmp_memberId;
			}
			else {
				m_memberId = tmp_memberId;
				is.ignore();
				is>>m_dueDate;
				
				//cout << "****" << m_dueDate;
			}
			//is.ignore();
			
		}
		else {
			cout << "No define media type" << endl;
		}

		return is;
	}

	std::ostream& Book::write(std::ostream& os)const {
		if (mediaType() == SDDS_CONSOLE) {
			os.fill(' ');
			os.width(41);
			os << std::left << name();
			//cout << "****" << endl;
			os.fill('0');
			os.width(13);
			os << std::right << m_isbn;

			os << "  ";

			os << shelfNo();

			if (m_memberId != 0) {
				os << " ";
				os.fill('0');
				os.width(5);
				os << std::right << m_memberId;
				os << "   " << m_dueDate;
			}
			os.fill(' ');
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID();
			os << name();
			os << "\t";
			os << m_isbn;
			os << "\t";
			os << shelfNo();
			os << "\t";
			os << m_memberId;
			if (m_memberId != 0) {
				os << "\t";
				os << m_dueDate;
			}
			os << endl;
		}
		else {
			os << "No media type defined!" << endl;
		}

		return os;
	}

}

