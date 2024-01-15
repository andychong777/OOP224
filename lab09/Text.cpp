/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
   int Text::getFileLength() const
   {
      std::ifstream file(m_filename, std::ios::binary | std::ios::ate);
      return file.tellg();
   }

   Text::Text(const char *filename) : m_filename(nullptr), m_content(nullptr)
   {
      if (filename)
      {
         m_filename = new char[strLen(filename) + 1];
         strCpy(m_filename, filename);
         read();
      }
   }

   // The rule of three
   Text::Text(const Text &src) : m_filename(nullptr), m_content(nullptr)
   {
      *this = src;
   }

   Text &Text::operator=(const Text &src)
   {
      if (this != &src)
      {
         delete[] m_filename;
         delete[] m_content;

         if (src.m_filename)
         {
            m_filename = new char[strlen(src.m_filename) + 1];
            strcpy(m_filename, src.m_filename);
         }

         if (src.m_content)
         {
            m_content = new char[strlen(src.m_content) + 1];
            strcpy(m_content, src.m_content);
            m_content[strlen(src.m_content)] = '\0';
         }
      }
      return *this;
   }

   Text::~Text()
   {
      delete[] m_filename;
      delete[] m_content;
   }

   void Text::read()
   {
      std::ifstream file(m_filename);

      if (file)
      {
         file.seekg(0, std::ios::end);
         std::streamsize size = file.tellg();
         file.seekg(0, std::ios::beg);

         delete[] m_content;
         m_content = new char[size + 1];

         if (file.read(m_content, size))
         {
            m_content[size] = '\0';
         }
      }
   }

   void Text::write(std::ostream &os) const
   {
      if (m_content)
         os << m_content;
   }

   std::ostream &operator<<(std::ostream &os, const Text &src)
   {
      src.write(os);
      return os;
   }

   const char *Text::getContent() const
   {
      return m_content;
   }
}