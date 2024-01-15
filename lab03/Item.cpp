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
#include "Item.h"
using namespace std;
namespace sdds
{
    void Item::setName(const char *name)
    {
        strnCpy(m_itemName, name, 20);
    }

    void Item::setEmpty()
    {
        m_price = 0.0;
        setName("");
    }

    void Item::set(const char *name, double price, bool taxed)
    {
        if (price < 0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            m_price = price;
            m_taxed = taxed;
            setName(name);
        }

    }

    void Item::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(20);
            cout.fill('.');
            cout << m_itemName;
            cout << " | ";
            cout.unsetf(ios::left);

            cout.setf(ios::right);
            cout.width(7);
            cout.fill(' ');
            cout << fixed;
            cout.precision(2);
            cout << m_price;
            cout << " | ";
            cout.unsetf(ios::right);

            m_taxed ? cout << "Yes" : cout << "No ";
            cout << " |";
            cout << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
        
    }

    bool Item::isValid() const
    {
        return (m_itemName[0] != '\0' && m_itemName);
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        const double taxRate = 0.13;

        if (m_taxed)
        {
            return m_price * taxRate;
        }
        else
        {
            return 0.0;
        }
    }
}