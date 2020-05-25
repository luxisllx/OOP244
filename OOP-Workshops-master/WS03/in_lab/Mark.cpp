
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"
using namespace std;

namespace sdds {

		void Mark::flushKeyboard()const {

			char newline;
			do {
				newline = cin.get();
				if (newline == '\n') {
					break;
				}
			}
			while (1);
		}

	
		void Mark::set(int displayMode) {

			m_displayMode = displayMode;
		}

		void Mark::set(double mark, int outOf) {

			m_mark = mark;
			m_outOf = outOf;

		}

		void Mark::setEmpty() {

			m_displayMode = DSP_UNDEFINED;
			m_mark = -1;
			m_outOf = 100;
		}

		bool Mark::isEmpty()const {
			if (m_mark == -1)
				return true;
			else {
				return false;
			}
		}

		int Mark::percent()const {

			return int((m_mark / m_outOf) * 100 + 0.5);		
		}
		double Mark::rawValue()const {

			return m_mark / m_outOf;
		}

		bool Mark::read(const char* prompt) {

			cout << prompt;
			cin >> m_mark;
			cin.get();
			cin >> m_outOf;

			if (cin.fail()) {
				cin.clear();
				setEmpty();

				flushKeyboard();
				return false;
			}
			else {
				flushKeyboard();
				return true;
			}	
		}

		ostream& Mark::display() const {

			if (isEmpty()) {
				cout << "Empty Mark object!";
			}
			else {

				if (m_displayMode == DSP_RAW) {
					cout << rawValue();
				}
				else if (m_displayMode == DSP_PERCENT) {
					cout << "%" << percent();
				}
				else if (m_displayMode == DSP_ASIS) {
					cout << m_mark << "/" << m_outOf;
				}
				else if (m_displayMode == DSP_UNDEFINED) {
					cout << "Display mode not set!";
				}
				else {
					cout << "Invalid Mark Display setting!";
				}
			}
			return cout;
		}
}