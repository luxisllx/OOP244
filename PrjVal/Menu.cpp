
// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019



#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
using namespace std;
#include "Menu.h"
namespace sdds {

	MenuItem::MenuItem(const char* new_description) {
		description = new char[strlen(new_description)+1];
		strcpy(description, new_description);
	}

	MenuItem::operator bool() const {
		return strcmp(description, "") != 0;
	}

	MenuItem::operator const char* () const {
		return description;
	}

	MenuItem::~MenuItem() {
		delete[] description;
	}

	std::ostream& MenuItem::display(std::ostream& os)const {
		os << description;
		return os;
	}
	
	Menu::Menu(const char* new_title ) : title(new_title){
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			items[i] = nullptr;
		}
		total = 0;
	}

	std::ostream& Menu::display(std::ostream& os)const {
		title.display(os);
		return os;
	}

	std::ostream& Menu::displayAll(std::ostream& os)const {
		if(title){
			title.display(os);
			os << ":" << endl;
		}
		for (int i = 0; i < total; i++) {
			os << " " << i+1 << "- ";
			items[i]->display(os);
			os << endl;
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;
	}

	Menu& Menu::operator<<(const char* new_description) {
		if (total < MAX_MENU_ITEMS) {
			items[total] = new MenuItem(new_description);
			total = total + 1;
		}
		
		return *this;
	}

	unsigned int Menu::getSelection() const {
		unsigned int selection;
		displayAll(cout);
		cin >> selection;
		
		while (cin.fail() || selection < (unsigned)0 || selection > (unsigned)total ) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Selection, try again: ";
			cin >> selection;
		}
		cin.ignore();
		return selection;
	}

	unsigned int Menu::operator~() const {
		unsigned int selection;
		displayAll(cout);
		cin >> selection;
		while (cin.fail() || selection<(unsigned)0 || selection > (unsigned)total ) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Selection, try again: ";
			cin >> selection;
		}
		cin.ignore();
		return selection;
	}

	Menu::operator int() const {
		return total;
	}

	Menu::operator unsigned int() const {
		return total;
	}

	Menu::operator bool() const {
		return total > 0;
	}

	ostream& operator<<(ostream& output, const Menu& M) {
		return M.display();
	}

	const char * Menu::operator[] (int index)const {
		
		if (index >= total) {
			index = index - total;
		}
		
		return *items[index];
	}

       	Menu::~Menu(){
		for(int i=0; i< total;i++){
			delete items[i];
		}	
	}
	


}
