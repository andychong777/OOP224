/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (DIY)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
#include <iostream>
using namespace std;

namespace sdds
{
    const char defautSymbol[9] = "+-+|+-+|";
    
    class Label
    {
    private:
        char symbol[9];
        char *text;

    public:
        // Creates an empty label and defaults the frame to "+-+|+-+|"
        Label();

        // Creates an empty label and sets the frame to the frameArg argument.
        Label(const char *frameArg);

        // Creates a Label with the frame set to frameArg
        // and the content of the Label set to the corresponding argument.
        Label(const char *frameArg, const char *content);

        // Makes sure there is no memory leak when the label goes out of scope.
        ~Label();

        // Reads the label from console up to 70 characters and stores it in the Label
        void readLabel();

        // Prints the label by drawing the frame
        std::ostream &printLabel() const;
    };

}

#endif // !SDDS_LABEL_H