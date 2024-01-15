/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds
{
   class Text
   {
      char *m_filename;
      char *m_content;
      void read();

   public:
      Text(const char *filename = nullptr);
      // implement rule of three here
      Text(const Text &src);
      Text &operator=(const Text &src);
      virtual ~Text();

      int getFileLength() const;
      virtual void write(std::ostream &os) const;
      const char *getContent() const;
   };
   // prototype of insertion overload into ostream goes here
   std::ostream &operator<<(std::ostream &os, const Text &src);
}
#endif // !SDDS_PERSON_H__
