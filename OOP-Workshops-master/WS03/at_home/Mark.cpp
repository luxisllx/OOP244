// COURSE: OOP244 LAB 03
// NAME: LUXI LIANG
// STUDENT #: 216936188
// DATE: 09-28-2019lliang44


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
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
		} while (1);
	}

	void Mark::prnLetter()const {
		if (m_mark != -1) {
			int grade = percent();
			if (grade > 100) {
				cout << "?";
			}

				else if (grade >= 90 && grade <= 100) {
					cout << "A+";
				}
				else if (grade >= 80 && grade <= 89) {
					cout << "A";
				}
				else if (grade >= 75 && grade <= 79) {
					cout << "B+";
				}
				else if (grade >= 70 && grade <= 74) {
					cout << "B";
				}
				else if (grade >= 65 && grade <= 69) {
					cout << "C+";
				}
				else if (grade >= 60 && grade <= 64) {
					cout << "C";
				}
				else if (grade >= 55 && grade <= 59) {
					cout << "D+";
				}
				else if (grade >= 50 && grade <= 54) {
					cout << "D";
				}
				else if (grade >= 0 && grade <= 49) {
					cout << "F";
				}
			
			else {

			}
		}
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
		strcpy(m_name, "");		// copy m_name into string. m_name is a pointer, so don't use "=" to something
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

	ostream& Mark::display(int width)const{

		if (m_name[0] != '\0') {

			int remain;								// setting variable remain to calculate how many change to dots
			remain = width - strlen(m_name);		// using function stringlength to calculate length of m_name
			cout << m_name;

			for (int i = 0; i < remain; i++) {		// using for loop to add a "." for each remaining space
				cout << ".";					
			}
		}
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else {

			if (m_displayMode == DSP_RAW) {
				cout << std::fixed << std::setprecision(2) << rawValue();	//using setprecision to get value with...
																			// ...2 digits after decimal points
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout << std::fixed << std::setprecision(1) << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else if (m_displayMode == DSP_LETTER) {
				prnLetter();
			}
			else if (m_displayMode == DSP_GPA) {
				cout << std::fixed << std::setprecision(1) << GPA(); 
			}
			else {
				cout << "Invalid Mark Display setting!";
			}
		}
		return cout;
	}

	void Mark::set(const char* name) {		// setting member m_name
		strncpy(m_name, name, 51);			// use strncpy when there is a max length 
	}

	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);					// setting value for name
		set(rawMark, outof);		// setting value for rawMark and outof
	}

	bool Mark::readName(const char* prompt, int maxLen) {
		cout << prompt;

		if (maxLen > 50) {
			maxLen = 50;
		}
	
		char* value;						// +1 because we want 1 extra space in our array
		value = new char[maxLen+1];			// dynamically allocate value as maxlength.
		cin.getline(value, maxLen+1);		// get.line: reads a string or line from input stream. read maxlength value

		if (cin.fail()) {
			cin.clear();
			flushKeyboard();
			strcpy(m_name, "");			// use strcpy when copying a string
			return false;
		}
		strcpy(m_name, value);
		return true;
	}

	void Mark::changeOutOf(int value) {
		
		m_mark = ((double)value / m_outOf)* m_mark;		// adjust m_mark value
		m_outOf = value;

		if (value < 1) {
			setEmpty();		// setting mark to safe empty state if value is less than 1
		}	
	}

	double Mark::GPA()const {
		
		double gpa;
		gpa = rawValue() * 4;			//can multiply a function directly because rawValue returns a double
		return gpa;
	}

	double Mark::letterBasedGPA()const {
		
			int grade = percent();

				if (grade >= 90 && grade <= 100) {
					return 4.0;
				}
				if (grade >= 80 && grade <= 89) {
					return 4.0;
				}
				if (grade >= 75 && grade <= 79) {
					return 3.5;
				}
				if (grade >= 70 && grade <= 74) {
					return 3.0;
				}
				if (grade >= 65 && grade <= 69) {
					return 2.5;
				}
				if (grade >= 60 && grade <= 64) {
					return 2.0;
				}
				if (grade >= 55 && grade <= 59) {
					return 1.5;
				}
				if (grade >= 50 && grade <= 54) {
					return 1.0;
				}
				if (grade >= 0 && grade <= 49) {
					return 0.0;
				}
				return 0;
	}
	
}
	
		
	



	
