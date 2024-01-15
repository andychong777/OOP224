/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds{
    class LblShape: public Shape{
        private:
            char* m_label;

        protected:
            const char* label() const;

        public:
            LblShape();
            LblShape(const char* lbl);
            ~LblShape();

            void getSpecs(istream &istr);
    };
}
#endif