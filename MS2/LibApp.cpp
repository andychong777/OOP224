/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Andy Chong
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "LibApp.h"
namespace sdds
{
    LibApp::~LibApp() = default;

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
    }

    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }

    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl
             << endl;
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;

        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl;
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed" << endl
                 << endl;
        }
    }
    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out" << endl
                 << endl;
        }
    }

    LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"),
                       m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        load();
    }

    void LibApp::run()
    {
        bool flag = false;

        while (flag == false)
        {
            int selection = m_mainMenu.run();
            switch (selection)
            {
            case 1: // New Publication
                newPublication();
                break;
            case 2: // Remove Publication
                removePublication();
                break;
            case 3: // Check out
                checkOutPub();
                break;
            case 4: // Return publication
                returnPub();
                break;
            case 0: // Exit
                if (m_changed)
                {
                    switch (m_exitMenu.run())
                    {
                    case 1:
                        save();
                        flag = true;
                        break;
                    case 2:
                        cout << endl;
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?"))
                            flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        cout << "\n-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
