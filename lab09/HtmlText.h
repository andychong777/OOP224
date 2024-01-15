/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #9 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds
{
   class HtmlText : public Text
   {
      char *m_title;

   public:
      HtmlText(const char *filename = nullptr, const char *title = nullptr);
      // rule of three goes here
      HtmlText(const HtmlText &src);
      HtmlText &operator=(const HtmlText &src);
      virtual ~HtmlText();

      virtual void write(std::ostream &os) const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
