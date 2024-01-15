/////////////////////////////////////////////////////////////////////////*/
// Final Project Milestone 4
// Book Module
// File	Book.cpp
// Version 1.0
// Author	Andy Chong
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds
{

    Book &Book::setEmpty()
    {
        if (m_author)
        {
            delete[] m_author;
            m_author = nullptr;
        }
        return *this;
    }

    Book::Book() : m_author(nullptr) {}

    Book::~Book()
    {
        delete[] m_author;
    }

    Book::Book(const Book &book) : Publication(book)
    {
        if (book.m_author)
        {
            m_author = new char[strlen(book.m_author) + 1];
            strcpy(m_author, book.m_author);
        }
        else
        {
            m_author = nullptr;
        }
    }

    Book &Book::operator=(const Book &book)
    {
        if (this != &book)
        {
            delete[] m_author;
            if (book.m_author)
            {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
            else
            {
                m_author = nullptr;
            }
            Publication::operator=(book);
        }
        return *this;
    }

    char Book::type() const
    {
        return 'B';
    }

    std::ostream &Book::write(std::ostream &os) const
    {
        Publication::write(os);
        if (os.rdbuf() == cout.rdbuf())
        {
            os << " " << setw(SDDS_AUTHOR_WIDTH) << setfill('.') << left << m_author << " |";
        }
        else
        {
            os << '\t' << m_author;
        }
        return os;
    }

    std::istream &Book::read(std::istream &is)
    {
        Publication::read(is);
        setEmpty();
        char temp_author[256];
        if (is.rdbuf() == cin.rdbuf())
        {
            cout << "Author: ";
        }
        is.ignore();
        is.getline(temp_author, 256);
        if (!is.fail())
        {
            m_author = new char[strlen(temp_author) + 1];
            strcpy(m_author, temp_author);
        }
        return is;
    }

    void Book::set(int member_id)
    {
        Publication::set(member_id);
        resetDate();
    }

    Book::operator bool() const
    {
        return m_author != nullptr && m_author[0] != '\0' && Publication::operator bool();
    }
}