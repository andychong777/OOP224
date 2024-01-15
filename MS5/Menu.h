/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author	Andy Chong
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef MENU_H
#define MENU_H
#include <iostream>
#define MAX_MENU_ITEMS 20

using namespace std;
namespace sdds
{
	class Menu;
	class MenuItem
	{
	private:
		char *m_content{};

		operator bool() const;
		operator const char *() const;
		ostream &display(ostream &os);

		MenuItem(const MenuItem &m) = delete;
		MenuItem &operator=(const MenuItem &m) = delete;

		MenuItem();
		MenuItem(const char *content);
		~MenuItem();

		friend class Menu;
	};
	class Menu
	{
	private:
		MenuItem m_title{};
		MenuItem *m_items[MAX_MENU_ITEMS]{};
		int m_count{};

	public:
		Menu();
		Menu(const char *);
		~Menu();

		Menu(const Menu &m) = delete;
		Menu &operator=(const Menu &m) = delete;

		ostream &display(ostream &os);
		ostream &displayMenu(ostream &os = cout);

		Menu &operator<<(const char *);
		operator int();
		operator unsigned int();
		operator bool();
		int operator~();
		const char *operator[](int index) const;

		unsigned int run();
	};
	ostream &operator<<(ostream &os, Menu &menu);

}

#endif // !MENU_H