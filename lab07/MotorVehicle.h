/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>

namespace sdds
{
    class MotorVehicle
    {
        private:
            char licPlate[9];
            char address[64];
            int year;

        public:
            MotorVehicle();
            MotorVehicle(const char* lp, int yr);

            void moveTo(const char* addr);

            std::ostream &write(std::ostream &os) const;
            std::istream &read(std::istream &is);
    };
    std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &mv);
    std::istream &operator>>(std::istream &istr, MotorVehicle &mv);
}
#endif // !SDDS_MOTORVEHICLE_H__ 
