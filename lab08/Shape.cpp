/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "Shape.h"

namespace sdds{
    ostream &operator<<(ostream &ostr, const Shape &shape){
        shape.draw(ostr);
        return ostr;
    }

    istream &operator>>(istream &istr, Shape &shape){
        shape.getSpecs(istr);
        return istr;
    }
}