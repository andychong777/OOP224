/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds{
    class Rectangle: public LblShape{
        private:
            int m_width;
            int m_height;

        public:
            Rectangle();
            Rectangle(const char* lbl, const int width, const int height);

            void getSpecs(istream &istr);
            void draw(ostream &ostr) const;
    };
}
#endif