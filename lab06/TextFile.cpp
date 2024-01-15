/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (part 1)
Full Name  : Andy Chong
Student ID#: 150588229
Email      : achong11@myseneca.ca
Section    : NHH

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Line::operator const char *() const
    {
        return (const char *)m_value;
    }

    Line &Line::operator=(const char *lineValue)
    {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line()
    {
        delete[] m_value;
    }

    void TextFile::setEmpty()
    {

        if (m_textLines != nullptr)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }

        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char *fname, bool isCopy)
    {
        if (isCopy)
        {

            m_filename = new char[strLen(m_prefix) + strLen(fname) + 1];
            strCpy(m_filename, m_prefix);
            strCat(m_filename, fname);
        }
        else
        {

            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines()
    {
        ifstream readfile(m_filename);
        char read_Char;

        if (readfile.is_open())
        {
            while (readfile)
            {

                readfile.get(read_Char);

                if (read_Char == '\n')
                    m_noOfLines++;
            }

            m_noOfLines++;
        }
        else
        {

            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr)
        {

            if (m_textLines != nullptr)
            {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            m_textLines = new Line[m_noOfLines];

            ifstream readfile(m_filename);
            string _eachLine;
            unsigned count = 0;

            if (readfile.is_open())
            {

                while (getline(readfile, _eachLine))
                {
                    m_textLines[count].m_value = new char[strLen(_eachLine.c_str()) + 1];
                    strCpy(m_textLines[count].m_value, _eachLine.c_str());
                    count++;
                }
            }

            m_noOfLines = count;
        }
    }

    void TextFile::saveAs(const char *fileName) const
    {

        ofstream out(fileName);

        for (unsigned i = 0; i < m_noOfLines; i++)
            out << m_textLines[i] << endl;
    }

    TextFile::TextFile(unsigned pageSize)
    {

        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char *filename, unsigned pageSize)
    {

        setEmpty();

        m_pageSize = pageSize;

        if (filename != nullptr && filename[0] != '\0')
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);

            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile &src)
    {
        setEmpty();
        this->m_pageSize = src.m_pageSize;

        if (this != &src)
        {
            if (src.m_textLines && src.m_noOfLines > 0)
            {

                setFilename(src.m_filename, true);

                this->m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;
                while (i < m_noOfLines)
                {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
        }
    }

    TextFile &TextFile::operator=(const TextFile &src)
    {
        if (this != &src)
        {

            if (m_textLines != nullptr)
            {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            if (src.m_textLines && src.m_noOfLines > 0)
            {
                this->m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;
                while (i < m_noOfLines)
                {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
        }

        return *this;
    }

    TextFile::~TextFile()
    {
        if (m_textLines != nullptr)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    const char *TextFile::name() const
    {
        return m_filename;
    }

    std::ostream &TextFile::view(std::ostream &ostr) const
    {
        if (m_filename != nullptr && m_filename[0] != '\0')
        {
            ostr << m_filename << endl;

            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << '=' << endl;

            unsigned i = 0;

            while (i < m_noOfLines && i < m_pageSize)
            {
                ostr << m_textLines[i] << endl;
                i++;
            }

            if (i < m_noOfLines)
            {
                do
                {
                    ostr << "Hit ENTER to continue...";
                    char x;
                    cin.get(x);

                    for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++)
                    {
                        ostr << m_textLines[i] << endl;
                        i++;
                    }
                } while (i < m_noOfLines);
            }
        }

        return ostr;
    }

    std::istream &TextFile::getFile(std::istream &istr)
    {
        string _input;

        istr >> _input;

        m_filename = new char[strLen(_input.c_str()) + 1];
        strCpy(m_filename, _input.c_str());
        istr.ignore(32767, '\n');

        setNoOfLines();
        loadText();

        return istr;
    }

    const char *TextFile::operator[](unsigned index) const
    {
        if (m_filename != nullptr && m_filename[0] != '\0')
        {
            if (index >= m_noOfLines)
                index -= m_noOfLines;
        }

        return m_textLines[index].m_value;
    }

    TextFile::operator bool() const
    {
        bool result = false;

        if (m_textLines != nullptr)
            result = true;

        return result;
    }

    std::ostream &operator<<(std::ostream &ostr, const TextFile &text)
    {
        text.view(ostr);
        return ostr;
    }

    std::istream &operator>>(std::istream &istr, TextFile &text)
    {
        text.getFile(istr);
        return istr;
    }
}