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
#include "HtmlText.h"
#include "cstring.h"

namespace sdds
{
  HtmlText::HtmlText(const char *filename, const char *title) : Text(filename)
  {
    if (title)
    {
      m_title = new char[strLen(title) + 1];
      strCpy(m_title, title);
    }
  }

  // The rule of three
  HtmlText::HtmlText(const HtmlText &src) : Text(src), m_title(nullptr)
  {
    if (src.m_title)
    {
      m_title = new char[strlen(src.m_title) + 1];
      strcpy(m_title, src.m_title);
    }
  }

  HtmlText &HtmlText::operator=(const HtmlText &src)
  {
    if (this != &src)
    {
      delete[] m_title;
      Text::operator=(src);
      if (src.m_title)
      {
        m_title = new char[strlen(src.m_title) + 1];
        strcpy(m_title, src.m_title);
      }
    }
    return *this;
  }

  HtmlText::~HtmlText()
  {
    delete[] m_title;
  }

  void HtmlText::write(std::ostream &os) const
  {
    bool MS = false;
    os << "<html><head><title>";
    if (m_title)
    {
      os << m_title;
    }
    else
    {
      os << "No Title";
    }
    os << "</title></head>\n<body>\n";
    if (m_title)
    {
      os << "<h1>" << m_title << "</h1>\n";
    }
    for (int i = 0; i < strlen(getContent()); i++)
    {
      char ch = getContent()[i];
      if (ch == ' ')
      {
        if (MS)
        {
          os << "&nbsp;";
        }
        else
        {
          os << ' ';
          MS = true;
        }
      }
      else if (ch == '<')
      {
        os << "&lt;";
        MS = false;
      }
      else if (ch == '>')
      {
        os << "&gt;";
        MS = false;
      }
      else if (ch == '\n')
      {
        os << "<br />\n";
        MS = false;
      }
      else
      {
        os << ch;
        MS = false;
      }
    }
    os << "</body>\n</html>";
  }
}