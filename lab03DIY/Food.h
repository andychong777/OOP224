/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
    class Food
    {
    private:
        char foodName[31];
        int calNum;
        int mealTime;

    public:
        ~Food();
        Food();

        bool isValid() const;
        int calorie() const;

        void set(const char *name, int calories, int time);

        void display() const;
        void display(const char *name) const;
        void display(int time) const;
    };
}

#endif