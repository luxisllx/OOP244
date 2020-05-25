// OOP244 Section NEE
// Milestone 01
// Luxi Liang
// November 21, 2019


#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

using namespace std;
namespace sdds {

	const int MAX_MENU_ITEMS = 20;

	class MenuItem {
	private:
		char* description;
		MenuItem(const char* new_description = "");
		~MenuItem();
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;
		operator bool() const;
		operator const char*() const;
		std::ostream& display(std::ostream& os = std::cout)const;



		friend class Menu;
	};

	class Menu {
	private:
		MenuItem title;
		MenuItem* items[MAX_MENU_ITEMS];
		int total;
		int hello[20];

		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;
	public:
		Menu(const char* new_title = "");
		std::ostream& display(std::ostream& os = std::cout)const;
		std::ostream& displayAll(std::ostream& os = std::cout)const;
		Menu& operator<<(const char * );
		unsigned int getSelection() const;
		unsigned int operator~() const;
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char * operator[] (int) const;

		friend ostream& operator<<(ostream& output, const Menu& M);
		
		
	};

}
#endif