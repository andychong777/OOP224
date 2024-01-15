/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (Part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Canister.h"
using namespace std;
namespace sdds
{
    void Canister::setToDefault()
    {

        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char *Cstr)
    {
        if (Cstr != nullptr && m_usable)
        {
            delete[] m_contentName;
            size_t length = strlen(Cstr);
            m_contentName = new char[length + 1];
            strcpy(m_contentName, Cstr);
        }
    }

    bool Canister::isEmpty() const
    {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister &C) const
    {
        bool result = false;

        if (this->m_contentName != nullptr && C.m_contentName != nullptr)
        {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)
                result = true;
        }

        return result;
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char *contentName)
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter,
                       const char *contentName)
    {
        setToDefault();

        if (height >= 10.0 && diameter >= 10 && height <= 40 && diameter <= 30)
        {
            m_height = height;
            m_diameter = diameter;
            m_usable = true;
            setName(contentName);
        }
        else
        {
            m_usable = false;
        }
    }

    Canister::~Canister()
    {
        if (m_contentName)
        {
            delete[] m_contentName;
            m_contentName = nullptr;
        }
    }

    Canister &Canister::setContent(const char *contentName)
    {
        if (contentName == nullptr || contentName[0] == '\0')
        {
            m_usable = false;
        }
        else if (isEmpty())
        {
            setName(contentName);
        }
        else if (!hasSameContent(*this))
        {
            m_usable = false;
        }
        return *this;
    }

    Canister &Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0.0 && (quantity + volume()) <= capacity())
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }
        return *this;
    }

    Canister &Canister::pour(Canister &C)
    {

        setContent(C.m_contentName);

        double remainingCapacity = capacity() - volume();

        if (C.volume() > (this->capacity() - this->volume()))
        {

            C.m_contentVolume -= (this->capacity() - this->volume());

            this->m_contentVolume = capacity();
        }
        else
        {

            pour(C.m_contentVolume);

            C.m_contentVolume = 0.0;
        }

        return *this;
    }

    double Canister::volume() const
    {
        return m_contentVolume;
    }

    std::ostream &Canister::display() const
    {

        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity();
        cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

        if (!m_usable)
            cout << " of Unusable content, discard!";
        else if (m_contentName != nullptr)
        {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << m_contentName;
        }

        cout.unsetf(ios::fixed);
        return cout;
    }

    double Canister::capacity() const
    {
        return 3.14159265359 * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear()
    {
        if (!m_usable)
        {
            delete[] m_contentName;
            m_contentName = nullptr;
            m_contentVolume = 0.0;
            m_usable = true;
        }
    }

}