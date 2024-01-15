/* Citation and Sources...
Final Project Milestone 2
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	Menu::Menu()
	{
		m_count = 0;
	}

	Menu::operator int()
	{
		return m_count;
	}

	Menu::operator unsigned int()
	{
		return m_count;
	}

	Menu::operator bool()
	{
		return (m_count > 0);
	}

	int Menu::operator~()
	{
		return run();
	}

	ostream &operator<<(ostream &os, Menu &menu)
	{
		return menu.display(os);
	}

	MenuItem::MenuItem()
	{
		m_content = nullptr;
	}

	Menu::~Menu()
	{
		for (int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			delete m_items[i];
		}
	}

	unsigned int Menu::run()
	{
		displayMenu();
		return getInt(m_count);
	}

	Menu::Menu(const char *title) : m_title(title){};

	ostream &Menu::display(ostream &os)
	{
		if (m_title)
		{
			os << m_title.m_content;
		}
		return os;
	}

	ostream &Menu::displayMenu(ostream &os)
	{
		if (m_title)
		{
			os << m_title.m_content << endl;
			for (int i = 0; i < m_count; i++)
			{
				os << " " << i + 1 << "- " << m_items[i]->m_content << endl;
			}
			os << " 0- Exit" << endl;
			os << "> ";
		}
		else
		{
			cout << " 1- Order more" << endl;
			cout << " 0- Exit" << endl;
			cout << "> ";
		}
		return os;
	}

	Menu &Menu::operator<<(const char *content)
	{
		if (m_count < MAX_MENU_ITEMS)
		{
			MenuItem *newMenu = new MenuItem(content);
			m_items[m_count] = newMenu;
			m_count++;
		}
		return *this;
	}

	const char *Menu::operator[](int index) const
	{
		if (index > m_count)
		{
			index %= m_count;
			return m_items[index]->m_content;
		}
		else
		{
			return m_items[index]->m_content;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	MenuItem::operator bool() const
	{

		return m_content && m_content[0];
	}

	MenuItem::operator const char *() const
	{
		return m_content;
	}

	MenuItem::MenuItem(const char *content)
	{
		if (content && content[0])
		{
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else
		{
			m_content = nullptr;
		}
	}

	ostream &MenuItem::display(ostream &os)
	{
		if (m_content != 0)
		{
			os << m_content;
		}
		return os;
	}

}