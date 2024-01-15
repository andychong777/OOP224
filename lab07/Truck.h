/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
    class Truck : public MotorVehicle
    {
        private:
            MotorVehicle mv;
            double capacity;
            double load;

        public:
            Truck(const char* lp, int yr, double cap, const char* addr);

            bool addCargo(double cargo);
            bool unloadCargo();

            std::ostream &write(std::ostream &ostr) const;
            std::istream &read(std::istream &istr);
    };
    std::ostream &operator<<(std::ostream &ostr, const Truck &truck);
    std::istream &operator>>(std::istream &istr, Truck &truck);
}
#endif // !SDDS_TRUCK_H__ 