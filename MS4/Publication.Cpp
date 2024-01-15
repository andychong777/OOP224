/////////////////////////////////////////////////////////////////////////*/
// Final Project Milestone 4
// Publication Module
// File	Publication.cpp
// Version 1.0
// Author   Andy Chong
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "Publication.h"
using namespace std;
namespace sdds
{

    void Publication::resetDate()
    {
        m_date = Date();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char *title) const
    {
        return strstr(m_title, title) != nullptr;
    }

    Publication::operator const char *() const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(std::ios &io) const
    {
        return &io == &cout || &io == &cin;
    }

    Publication::operator bool() const
    {
        return m_title != nullptr && m_shelfId[0] != '\0';
    }

    Publication::~Publication()
    {
        delete[] m_title;
    }

    Publication &Publication::setEmpty()
    {
        if (m_title)
        {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
        return *this;
    }

    Publication &Publication::operator=(const Publication &Scr)
    {
        if (this != &Scr)
        {
            if (Scr)
            {
                if (m_title)
                {
                    delete[] m_title;
                    m_title = nullptr;
                }
                m_title = new char[strlen(Scr.m_title) + 1];
                strcpy(m_title, Scr.m_title);
                strcpy(m_shelfId, Scr.m_shelfId);
                m_membership = Scr.m_membership;
                m_libRef = Scr.m_libRef;
                m_date = Scr.m_date;
            }
        }
        return *this;
    }

    Publication::Publication(const Publication &Scr)
    {
        if (this != &Scr)
        {
            if (m_title)
            {
                delete[] m_title;
                m_title = nullptr;
            }
            m_title = new char[strlen(Scr.m_title) + 1];
            strcpy(m_title, Scr.m_title);
            strcpy(m_shelfId, Scr.m_shelfId);
            m_membership = Scr.m_membership;
            m_libRef = Scr.m_libRef;
            m_date = Scr.m_date;
        }
    }

    void Publication::set(int member_id)
    {
        if (member_id < 9999 || member_id > 99999)
        {
            m_membership = 0;
        }
        else
        {
            m_membership = member_id;
        }
    }

    void Publication::setRef(int value)
    {
        if (value > -1)
        {
            m_libRef = value;
        }
        else
        {
            m_libRef = -1;
        }
    }

    ostream &Publication::write(ostream &ostr) const
    {
        char title[SDDS_TITLE_WIDTH + 1]{};
        strncpy(title, m_title, SDDS_TITLE_WIDTH);
        if (conIO(ostr))
        {
            ostr << "| " << m_shelfId << " | ";
            ostr << setw(30) << setfill('.') << left << title;
            ostr << " | ";
            (m_membership > 0) ? ostr << m_membership : ostr << " N/A ";
            ostr << " | " << m_date << " |";
        }
        else
        {
            ostr << type();
            ostr << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
        }
        return ostr;
    }

    istream &Publication::read(istream &istr)
    {
        char tmp_title[256]{};
        char tmp_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        unsigned int tmp_membership{};
        int tmp_libRef{};
        Date tmp_date{};
        setEmpty();
        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1);
            if (strlen(tmp_shelfId) != SDDS_SHELF_ID_LEN)
                istr.setstate(ios_base::failbit);
            cout << "Title: ";
            istr.getline(tmp_title, 256);
            cout << "Date: ";
            istr >> tmp_date;
        }
        else
        {
            istr >> tmp_libRef;
            istr.ignore();
            istr.getline(tmp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            istr.getline(tmp_title, 256, '\t');
            istr >> tmp_membership;
            istr.ignore();
            istr >> tmp_date;
        }
        if (!tmp_date)
            istr.setstate(ios_base::failbit);
        if (!istr.fail())
        {
            m_title = new char[strlen(tmp_title) + 1];
            strcpy(m_title, tmp_title);
            strcpy(m_shelfId, tmp_shelfId);
            m_membership = tmp_membership;
            m_date = tmp_date;
            m_libRef = tmp_libRef;
        }
        return istr;
    }

}