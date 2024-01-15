/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <cstring>
#include "Line.h"

namespace sdds{
    Line::Line(): LblShape(){
        m_length = 0;
    }

    Line::Line(const char* lbl, int len): LblShape(lbl){
        m_length = len;
    }

    void Line::getSpecs(istream &istr){
        LblShape::getSpecs(istr);

        int len;
        istr >> len;

        if(istr.fail()){
            len = 0;
        }
        m_length = len;

        istr.clear();
        istr.ignore(10000, '\n');       
    }

    void Line::draw(ostream &ostr) const{
        if(m_length > 0 && label() != nullptr){
            ostr << label() << endl;
            ostr.width(m_length);
            ostr.fill('=');
            ostr << '=';
        }
    }
}