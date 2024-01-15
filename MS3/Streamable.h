////////////////////////////////////////////////////////////////////////*/
// Final Project Milestone 3
// Streamable Module
// File	Streamable.h
// Version 1.0
// Author	Andy Chong
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//           
/////////////////////////////////////////////////////////////////

#pragma once
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>
namespace sdds {
	class Streamable
	{
	public:
        virtual ~Streamable();
		

        virtual std::ostream& write(std::ostream& os) const = 0;

        virtual std::istream& read(std::istream& is) = 0;

        virtual bool conIO(std::ios& io) const = 0;

        virtual operator bool() const = 0;
	};

    std::ostream& operator<<(std::ostream& os, const Streamable& s);

    std::istream& operator>>(std::istream& is, Streamable& s);
}
#endif // !SDDS_STREAMABLE_H
