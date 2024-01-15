/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 2.0
Author	Andy Chong
Revision History
-----------------------------------------------------------
Date      Reason
Aug 18    MS5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "LibApp.h"
#include "PublicationSelector.h"

using namespace std;

namespace sdds
{
    LibApp::~LibApp()
    {
        for (int i = 0; i < NOLP; i++)
        {
            delete PPA[i];
        }
    }

    bool LibApp::confirm(const char *message)
    {
        Menu confirmMenu(message);
        confirmMenu << "Yes";

        unsigned int selection = confirmMenu.run();

        return selection == 1;
    }

    void LibApp::load()
    {
        cout << "Loading Data" << endl;

        ifstream insideFile(m_filename);

        char type{};
        int i;

        for (i = 0; insideFile && i < SDDS_LIBRARY_CAPACITY; i++)
        {

            insideFile >> type;

            insideFile.ignore();

            if (insideFile)
            {
                if (type == 'P')
                    PPA[i] = new Publication;

                else if (type == 'B')
                    PPA[i] = new Book;

                if (PPA[i])
                {
                    insideFile >> *PPA[i];
                    NOLP++;
                    LLRN = PPA[i]->getRef();
                }
            }
        }
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream out_file(m_filename);
        int i;
        for (i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() != 0)
            {
                out_file << *PPA[i] << endl;
            }
        }

        out_file.close();
    }

    int LibApp::search(int searchType)
    {
        char title[256]{};
        int selected = 0, i = 0, libRef = 0;
        char typeChar;
        PublicationSelector pubSel("Select one of the following found matches:", 15);

    
        selected = m_pubTypeMenu.run();
        if (selected == 1)
        {
            typeChar = 'B';
        }
        else if (selected == 2)
        {
            typeChar = 'P';
        }


        cin.ignore(1000, '\n');
        cout << "Publication Title: ";
        cin.getline(title, 256);

        if (searchType == 1)
        {
            for (i = 0; i < NOLP; i++)
            {
                if (PPA[i]->operator==(title) && typeChar == PPA[i]->type() && PPA[i]->getRef() != 0)
                {

                    pubSel << PPA[i];
                }
            }
        }

        else if (searchType == 2)
        {
            for (i = 0; i < NOLP; i++)
            {
                if (PPA[i]->operator==(title) && PPA[i]->onLoan() && typeChar == PPA[i]->type() && PPA[i]->getRef() != 0)
                {
                    pubSel << PPA[i];
                }
            }
        }

        else if (searchType == 3)
        {
            for (i = 0; i < NOLP; i++)
            {
                if (PPA[i]->operator==(title) && !PPA[i]->onLoan() && typeChar == PPA[i]->type() && PPA[i]->getRef() != 0)
                {
                    pubSel << PPA[i];
                }
            }
        }

        if (pubSel)
        {
            pubSel.sort();
            libRef = pubSel.run();

            if (libRef > 0)
            {
                cout << *getPub(libRef) << endl;
            }
            else
            {
                cout << "Aborted!" << endl;
            }
        }
        else
        {
            cout << "No matches found!" << endl;
        }

        return libRef;
    }

    Publication *LibApp::getPub(int libRef)
    {
        Publication *result = nullptr;
        for (int i = 0; i < NOLP; i++)
        {
            if (PPA[i]->getRef() == libRef)
            {
                result = PPA[i];
            }
        }

        return result;
    }

    void LibApp::returnPub()
    {
        bool abort = false;
        cout << "Return publication to the library" << endl;
        int libRef = search(2);

        if (!(libRef > 0))
        {
            abort = true;
        }

        if (!abort)
        {
            bool confirmed = confirm("Return Publication?");

            if (confirmed)
            {
                int daysLoaned = Date() - getPub(libRef)->checkoutDate();

                if (daysLoaned > SDDS_MAX_LOAN_DAYS)
                {
                    double penalty = (daysLoaned - SDDS_MAX_LOAN_DAYS) * 0.5;
                    cout << fixed << setprecision(2);
                    cout << "Please pay $" << penalty << " penalty for being " << (daysLoaned - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }

                getPub(libRef)->set(0);
                m_changed = true;
            }

            cout << "Publication returned" << endl;
        }

        cout << endl;
    }

    void LibApp::newPublication()
    {
        bool abort = false;
        if (NOLP == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
            abort = true;
        }

        if (!abort)
        {
            cout << "Adding new publication to the library" << endl;

            // Getting the publication type from the user
            int pubType = m_pubTypeMenu.run();
            cin.ignore(1000, '\n');

            // Instantiating a dynamic publication
            Publication *p = nullptr;

            if (pubType == 0)
            {
                cout << "Aborted!" << endl;
                abort = true;
            }

            else if (pubType == 1)
            {
                p = new Book;
                cin >> *p;
            }

            else if (pubType == 2)
            {
                p = new Publication;
                cin >> *p;
            }

            if (cin.fail())
            {
                cin.ignore(1000, '\n');
                cin.clear();
                cout << "Aborted!" << endl;
                exit(0);
            }
            else
            {
                if (!abort && confirm("Add this publication to the library?"))
                {
                    if (!*p)
                    {
                        cout << "Failed to add publication!" << endl;
                        delete p;
                    }

                    else
                    {
                        LLRN++;
                        p->setRef(LLRN);

                        // Adding the publication object's address to the end of the PPA
                        PPA[NOLP] = p;

                        NOLP++;
                        m_changed = true;

                        cout << "Publication added" << endl;
                    }
                }
            }
        }

        cout << endl;
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search(1);
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl
                 << endl;
        }
    }
    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int check = search(3);
        bool valid = false;
        if (check > 0)
        {
            bool returnValue = confirm("Check out publication?");
            if (returnValue)
            {
                cout << "Enter Membership number: ";
                int membership;
                while (!valid)
                {
                    cin >> membership;
                    if (membership < 10000 || membership > 99999 || !cin)
                    {

                        cout << "Invalid membership number, try again: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                        valid = false;
                    }
                    else
                    {
                        valid = true;
                    }
                }
                getPub(check)->set(membership);
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
    }

    LibApp::LibApp(const char *filename) : m_changed(false), m_mainMenu("Seneca Library Application"),
                       m_exitMenu("Changes have been made to the data, what would you like to do?"),
                       m_pubTypeMenu("Choose the type of publication:")
    {
       if (filename)
        {
            strcpy(m_filename, filename);
        }

        m_changed = false;
        NOLP = 0;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";

        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";

        m_pubTypeMenu << "Book"
                      << "Publication";
        load();
    }

    void LibApp::run()
    {
         int input, exit;

        do
        {
            input = m_mainMenu.run();

            // Calling appropriate methods according to the choice of the user in the main menu
            switch (input)
            {
            case 0:
                if (m_changed == true)
                {
                    exit = m_exitMenu.run();
                    switch (exit)
                    {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            m_changed = false;
                        }
                        break;
                    case 1:
                        save();
                        input = 0;
                        break;
                    case 2:
                        input = 1;
                        break;
                    }
                }
                cout << endl;
                break;
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            }
        } while (input != 0); 

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
