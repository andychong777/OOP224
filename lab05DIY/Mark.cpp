/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
    // New Mark
    Mark::Mark()
    {
        mark = 0;
    }
    Mark::Mark(int mrk)
    {
        if (mrk < 0 || mrk > 100)
        {
            mark = -1;
            mark = -2147483647 - 1;
        }
        else
        {
            mark = mrk;
        }
    }

    Mark::operator int() const
    {
        if (mark < 0 || mark > 100)
        {
            return 0;
        }
        return mark;
    }

    Mark::operator double() const
    {
        double mrk = 0;
        if (mark >= 0 && mark < 50)
        {
            mrk = 0;
        }
        else if (mark >= 50 && mark < 60)
        {
            mrk = 1;
        }
        else if (mark >= 60 && mark < 70)
        {
            mrk = 2;
        }
        else if (mark >= 70 && mark < 80)
        {
            mrk = 3;
        }
        else if (mark >= 80 && mark <= 100)
        {
            mrk = 4;
        }
        return mrk;
    }

    Mark::operator char() const
    {
        char mrk = 'X';
        if (mark >= 0 && mark < 50)
        {
            mrk = 'F';
        }
        else if (mark >= 50 && mark < 60)
        {
            mrk = 'D';
        }
        else if (mark >= 60 && mark < 70)
        {
            mrk = 'C';
        }
        else if (mark >= 70 && mark < 80)
        {
            mrk = 'B';
        }
        else if (mark >= 80 && mark <= 100)
        {
            mrk = 'A';
        }
        return mrk;
    }

    Mark &Mark::operator+=(const int mrk)
    {
        mark += mrk;
        mark = int(*this);
        return *this;
    }

    Mark &Mark::operator=(const int mrk)
    {
        mark = mrk;
        mark = int(*this);
        return *this;
    }

    int operator+=(int &lhs, const Mark &mrk)
    {

        lhs += int(mrk);
        return lhs;
    }
}