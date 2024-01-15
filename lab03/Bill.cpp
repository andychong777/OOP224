/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (part1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds 
{
    void Bill::setEmpty()
    {
        strCpy(m_title, "");
        m_items = nullptr;
    }

    bool Bill::isValid()const
    {
        bool result = true;

        if (*m_title != '\0' && m_items != nullptr)
        {
            for (int i = 0; i < m_noOfItems && result; i++)
            {
                result = m_items[i].isValid();
            }
        }
        else
        {
            result = false;
        }
        return result;
    }

    double Bill::totalTax()const
    {
        int i;
        double totalTax = 0;

        for (i = 0; i < m_noOfItems; i++)
        {
            totalTax += m_items[i].tax();
        }

        return totalTax;
        
    }

    double Bill::totalPrice()const
    {
        int i;
        double totalPrice = 0;

        for (i = 0; i < m_noOfItems; i++)
        {
            totalPrice += m_items[i].price();
        }

        return totalPrice;
    }

    void Bill::Title()const
    {
        cout << "+--------------------------------------+" << endl;

        if(isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
            cout.unsetf(ios::left);
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;

        if(isValid())
        {
            cout << "|                Total Tax: ";
            cout.setf(ios::right);
            cout.width(10);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems <= 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
        }
        m_items = new Item[m_noOfItems];

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].setEmpty();
        }
        
        
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        int i, foundSubject = 0;
        bool result = false;

        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            result = true;
        }
        return result;
        
    }

    void Bill::display()const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = NULL;
    }
}