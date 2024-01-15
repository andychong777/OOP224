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
#include <string>
#include "LblShape.h"

namespace sdds{
    const char* LblShape::label() const{
        return m_label;
    }

    LblShape::LblShape(){
        m_label = nullptr;
    }

    LblShape::LblShape(const char* lbl){
        if(lbl != nullptr){
            m_label = new char[strlen(lbl) + 1];
            strcpy(m_label, lbl);
        }else{
            m_label = nullptr;
        }
    }

    Shape::~Shape(){
        
    }

    LblShape::~LblShape(){
        delete[] m_label;
        m_label = nullptr;
    }

    void LblShape::getSpecs(istream &istr){
        string lbl;
        getline(istr, lbl, ',');

        delete[] m_label;
        m_label = new char[strlen(lbl.c_str()) +1];
        strcpy(m_label, lbl.c_str());
    }
}