/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

using namespace std;
namespace sdds{
    class Shape{
        private:

        public:
            virtual ~Shape() = 0;
            virtual void draw(ostream &ostr) const = 0;
            virtual void getSpecs(istream &istr) = 0;
    };

    ostream &operator<<(ostream &ostr, const Shape &shape);
    istream &operator>>(istream &istr, Shape &shape);
}
#endif