/////////////////////////////////////////////////////////////////////////*/
// Final Project Milestone 5
// Book Module
// File	Book.cpp
// Version 1.0
// Author	Andy Chong
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

#include "Publication.h"

namespace sdds
{
    class Book : public Publication
    {
    private:
        char *m_author;

    public:
        Book &setEmpty();

        Book();
        Book(const Book &book);
        ~Book();

        Book &operator=(const Book &book);

        void set(int member_id);
        char type() const;
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);
        operator bool() const;
    };
}

#endif // !SDDS_BOOK_H
