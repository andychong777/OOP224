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
#include "Rectangle.h"

namespace sdds{
    Rectangle::Rectangle(): LblShape(){
        m_width = 0;
        m_height = 0;
    }

    Rectangle::Rectangle(const char* lbl, int width, int height): LblShape(lbl){
        m_width = width;
        m_height = height;
    }

    void Rectangle::getSpecs(istream &istr){
        LblShape::getSpecs(istr);

        int val;
        istr >> val;

        if(istr.fail()){
            val = 0;
        }
        m_width = val;

        char comma;
        istr >> comma >> val;

        if(istr.fail()){
            val = 0;
        }
        m_height = val;

        istr.clear();
        istr.ignore(10000, '\n');
    }

    void Rectangle::draw(ostream &ostr) const{
        // ostr << m_width << ":" << m_height << ":" << label() << endl;
        if(m_width > 1 && m_height > 1 && label() != nullptr){
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-';
            ostr << '+' << endl;

            ostr << '|' << label();
            ostr.width(m_width - strlen(label()) - 2);
            ostr.fill(' ');
            ostr << ' ';
            ostr << '|' << endl;

            for(int i=2; i<m_height - 1; i++){
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ';
                ostr << '|' << endl;
            }

            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-';
            ostr << '+';
        }
    }
}