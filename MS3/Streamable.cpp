////////////////////////////////////////////////////////////////////////*/
// Final Project Milestone 3
// Streamable Module
// File	Streamable.cpp
// Version 1.0
// Author	Andy Chong
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//           
/////////////////////////////////////////////////////////////////

#include "Streamable.h"

namespace sdds {
    Streamable::~Streamable() {};

    std::ostream& operator<<(std::ostream& os, const Streamable& s) {
        if (s) {    
            s.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s) {
        return (s.read(is));
    }
}