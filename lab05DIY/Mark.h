/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_Mark_H_
#define SDDS_Mark_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
    private:
        int mark;

    public:
        Mark();
        Mark(int mrk);

        operator int() const;
        operator double() const;
        operator char() const;

        Mark &operator+=(const int mrk);
        Mark &operator=(const int mrk);

        friend int operator+=(int &lhs, const Mark &mrk);
    };

}
#endif // SDDS_Mark_H_