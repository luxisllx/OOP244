// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string>
#include "Magazine.h"
using namespace std;

namespace sdds {
	Magazine::Magazine() {
		m_volume = 0;
		m_issueNumber = 0;		
	}

	Magazine::Magazine(const Magazine& m) : PubRecord(m){
		m_volume = m.m_volume;
		m_issueNumber = m.m_issueNumber;
	}

	Magazine::~Magazine() {

	}

	Magazine& Magazine::operator= (const Magazine& m) {
		PubRecord::operator=(m);
		m_volume = m.m_volume;
		m_issueNumber = m.m_issueNumber;

		return *this;
	}

	char Magazine::recID()const {
		return 'M';
	}

	void  Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	void  Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	std::istream& Magazine::read(std::istream& is) {
		if (mediaType() == SDDS_CONSOLE) {

			cout << "Magazine Name: ";
			char s[41];
			cin.getline(s, std::streamsize(40) + 1, '\n');
			while (is.fail()) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Magazine name too long, Enter again: ";
				cin.getline(s, std::streamsize(40) + 1, '\n');
			}

			cout << "Volume: ";
			int tmp_volume;
			is >> tmp_volume;
			while (is.fail() || tmp_volume > 99 || tmp_volume < 1) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Volume number, Enter again: ";
				is >> tmp_volume;
			}

			cout << "Issue: ";
			int tmp_issue;
			is >> tmp_issue;
			while (is.fail() || tmp_issue > 99 || tmp_issue < 1) {
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Issue number, Enter again: ";
				is >> tmp_issue;
			}

			cout << "Shelf Number: ";
			readShelfNo();

			//cout << "****" << s << "****";

			name(s);
			m_volume = tmp_volume;
			m_issueNumber = tmp_issue;

			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//cout << "****" << m_volume << "****" << m_issueNumber << "****" << shelfNo() << "****";
		}
		else if (mediaType() == SDDS_FILE) {
			char tmp_name[41];
			int tmp_volume;
			int tmp_issue;
			int tmp_shelf;
			//is >> tmp_name;
			is.getline(tmp_name, 40, '\t');
			//is.ignore();
			is >> tmp_volume;
			is.ignore();
			is >> tmp_issue;
			is.ignore();
			is >> tmp_shelf;
			if (is.fail()) {
				cout << " Magazine string is invalid"<< tmp_name <<"****"<< tmp_volume <<"****"<< tmp_issue <<"****" << tmp_shelf <<endl;
				is.clear();
				is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				name(tmp_name);
				m_volume = tmp_volume;
				m_issueNumber = tmp_issue;
				shelfNo(tmp_shelf);
			}
			is.ignore();
		}
		else {
			cout << "No define media type"<<endl;
		}

		return is;
	}

	std::ostream& Magazine::write(std::ostream& os)const {
		if (mediaType() == SDDS_CONSOLE) {
			os.fill(' ');
			os.width(41); 
			os << std::left << name();

			os << "       ";
			os.fill('0');
			os.width(2);
			os << std::right << m_volume;

			os << "(";

			os.width(2);
			os << std::right << m_issueNumber;

			os << ")  ";

			os << shelfNo();
			os.fill(' ');
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID();
			os << name();
			os << "\t";
			os << m_volume;
			os << "\t";
			os << m_issueNumber;
			os << "\t";
			os << shelfNo();
			os << endl;
		}
		else {
			os << "No media type defined!" << endl;
		}

		return os;
	}
}