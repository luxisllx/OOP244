// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "PubRecord.h"
using namespace std;

namespace sdds {

	PubRecord::PubRecord() {
		m_name = nullptr;
		m_shelfNo = 0;
		m_mediaType = SDDS_CONSOLE;
	}

	PubRecord::~PubRecord() {
		delete[] m_name;
		m_name = nullptr;
	}

	const char* PubRecord::getName()const {
		return m_name;
	}

	PubRecord::PubRecord(const PubRecord& pr) {
		
		name(pr.name());
		
		m_shelfNo = pr.shelfNo();

		m_mediaType = pr.mediaType();
	}

	PubRecord& PubRecord::operator=(const PubRecord& pr) {
		delete[] m_name;
		m_name = new char[strlen(pr.name()) + 1];
		strcpy(m_name, pr.name());

		m_shelfNo = pr.shelfNo();

		m_mediaType = pr.mediaType();

		return *this;
	}

	void PubRecord::mediaType(int mt) {
		m_mediaType = mt;
	}

	int PubRecord::mediaType()const {
		return m_mediaType;
	}

	int PubRecord::shelfNo()const {
		return m_shelfNo;
	}

	void PubRecord::readShelfNo() {
		int tmp;
		cin >> tmp;

		while (cin.fail() || tmp < 100 || tmp > 999) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Shelf Number, Enter again: ";
			cin >> tmp;
		}
		
		m_shelfNo = tmp;
	}

	void PubRecord::shelfNo(int value) {
		m_shelfNo = value;
	}

	bool PubRecord::operator==(char c)const {
		if (c == recID()) {
			return true;
		}
		else {
			return false;
		}
	}

	bool PubRecord::operator==(const char* s)const {
		if (strstr(m_name, s) == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	PubRecord::operator bool()const {
		if (m_name == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	void PubRecord::name(const char* name) {

		if (name == nullptr) {
			m_name = nullptr;
		}
		else {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}

	const char* PubRecord::name()const {
		return m_name;
	}

}
