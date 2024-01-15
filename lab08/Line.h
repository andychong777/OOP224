/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds{
    class Line: public LblShape{
        private:
            int m_length;

        public:
            Line();
            Line(const char* lbl, const int len);

            void getSpecs(istream &istr);
            void draw(ostream &ostr) const;
    };
}
#endif