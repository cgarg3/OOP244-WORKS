#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
using namespace std;

namespace sdds {

   // Constructor
   LibApp::LibApp() : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubMenu("Choose the type of publication:") {
      m_changed = false;

      // Populating main menu
      m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

      // Populating exit menu
      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

      load();
   }

   bool LibApp::confirm(const char* message) {
      bool done = false;
      Menu menu(message);
      menu << "Yes";

      int valueReturned = menu.run();
      if (valueReturned == 1) {
         done = true;
      }
      return done;
   }
   void LibApp::load() {
      std::cout << "Loading Data" << std::endl;

      std::ifstream infile(m_filename);
      char type{};

      for (int i = 0; infile; i++) {
         infile >> type;
         infile.ignore();

         if (infile) {
            if (type == 'P') {
               m_ppa[i] = new Publication;
            }
            else if (type == 'B') {
               m_ppa[i] = new Book;
            }
            else {
               std::cout << "no data" << std::endl;
            }

            if (m_ppa[i] && i < SDDS_LIBRARY_CAPACITY) {
               infile >> *m_ppa[i];
               m_llrn = m_ppa[i]->getRef();
               m_nolp++;
               //std::cout << m_nolp << std::endl;
            }
         }
      }
   }
   void LibApp::save() {
      std::cout << "Saving Data" << std::endl;

      std::ofstream outfile(m_filename);

      for (int i = 0; i < m_nolp; i++) {
         if (m_ppa[i]->getRef() != 0) {
            outfile << *m_ppa[i] << std::endl;
         }
      }
   }
   int LibApp::search(bool checkOut, bool onLoan) {
      PublicationSelector pb("Select one of the following found matches:");

      int selection = 0;
      char title[256]{};
      char type{};
      selection = m_pubMenu.run();

      selection == 1 ? type = 'B' : type = 'P';

      if (selection) {
         cout << "Publication Title: ";
         cin.getline(title, 256, '\n');

         if (checkOut && onLoan) {
            for (int i = 0; i < m_nolp; i++) {
               if (m_ppa[i]->type() == type && strstr(*m_ppa[i], title)) {
                  pb << m_ppa[i];
               }
            }

            if (pb) {
               pb.sort();
               int ref = pb.run();
               if (ref) {
                  return ref;
               }
               else {
                  cout << "Aborted!" << endl << endl;;
               }
            }
            else {
               cout << "No matches found!" << endl << endl;
            }
         }
         else if (checkOut) {
            for (int i = 0; i < m_nolp; i++) {

               if (m_ppa[i]->type() == type && strstr(*m_ppa[i], title)) {

                  if (!(m_ppa[i]->onLoan())) {

                     pb << m_ppa[i];
                  }
               }
            }

            if (pb) {
               pb.sort();
               int ref = pb.run();
               if (ref) {
                  return ref;
               }
               else {
                  cout << "Aborted!" << endl << endl;
               }
            }
            else {
               cout << "No matches found!" << endl << endl;
            }
         }
         else if (onLoan) {
            for (int i = 0; i < m_nolp; i++) {
               if (m_ppa[i]->type() == type && strstr(*m_ppa[i], title)) {

                  if (m_ppa[i]->onLoan()) {

                     pb << m_ppa[i];
                  }
               }
            }

            if (pb) {
               pb.sort();
               int ref = pb.run();
               if (ref) {
                  return ref;
               }
               else {
                  cout << "Aborted!" << endl << endl;;
               }
            }
            else {
               cout << "No matches found!" << endl << endl;
            }
         }
      }
      return 0;
      //std::cout << "Searching for publication" << std::endl; --> from milestone 2
   }
   void LibApp::returnPub() {
      std::cout << "Return publication to the library" << std::endl;

      int ref = search(false, true);

      if (ref) {
         cout << *getPub(ref) << endl;

         if (confirm("Return Publication?")) {
            Date date = getPub(ref)->checkoutDate();
            Date today;
            double amountToPay;
            int dayNum = (today - date);

            if (dayNum > 15) {
               amountToPay = (dayNum - 15) * 0.5;
               std::cout.setf(ios::fixed);
               std::cout.precision(2);
               std::cout << "Please pay $" << amountToPay
                  << " penalty for being " << (dayNum - 15) << " days late!" << std::endl;
            }
            getPub(ref)->set(0);
         }
         //std::cout << "Returning publication" << std::endl;
         std::cout << "Publication returned" << std::endl << std::endl;
         //std::cout << std::endl;
         m_changed = true;
      }
   }

   // Methods with confirmation
   void LibApp::newPublication() {

      if (m_nolp >= SDDS_LIBRARY_CAPACITY) {
         std::cout << "Library is at its maximum capacity!" << std::endl << std::endl;
      }
      else {
         std::cout << "Adding new publication to the library" << std::endl;
         Publication* p{};

         switch (m_pubMenu.run()) {
         case 0:
            std::cout << "Aborted!" << std::endl << std::endl;
            p = nullptr;
            break;
         case 1:
            p = new Book;
            break;
         case 2:
            p = new Publication;
            break;
         }

         if (p) {
            cin >> *p;
            if (cin) {
               if (confirm("Add this publication to the library?")) {
                  if ((*p)) {
                     m_changed = true;
                     m_ppa[m_nolp] = p;
                     m_llrn++;
                     m_ppa[m_nolp]->setRef(m_llrn);
                     m_nolp++;
                     std::cout << "Publication added" << std::endl << std::endl;
                  }
                  else { //when !*p
                     std::cout << "Failed to add publication!" << std::endl << std::endl;
                     delete p;
                  }
               }
               else { // when confirmation failed
                  delete p;
                  cout << "Aborted!" << std::endl << std::endl;
               }
            }
            else { // when cin failed
               delete p;
               std::cin.ignore(1000, '\n');
               std::cout << "Aborted!" << std::endl << std::endl;
            }
         }
      }
   }
   void LibApp::removePublication() {
      std::cout << "Removing publication from the library" << std::endl;
      int ref = search(true, true);

      if (ref) {
         cout << *getPub(ref) << endl;

         if (confirm("Remove this publication from the library?")) {
            getPub(ref)->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl << endl;
         }
      }
   }
   void LibApp::checkOutPub() {

      std::cout << "Checkout publication from the library" << std::endl;
      int ref = search(true, false);

      if (ref) {
         cout << *getPub(ref) << endl;

         if (confirm("Check out publication?")) {
            int membership_Num;
            cout << "Enter Membership number: ";
            cin >> membership_Num;
            while (!cin || (membership_Num < 10000 || membership_Num > 99999))
            {
               if (!cin) {
                  cin.clear();
                  cin.ignore(1024, '\n');
               }
               cout << "Invalid membership number, try again: ";

               cin >> membership_Num; // re-enter
               cin.ignore();
            }
            getPub(ref)->set(membership_Num);
            m_changed = true;
            cout << "Publication checked out" << endl << endl;
         }
      }
   }

   // Display main meny
   void LibApp::run() {
      int inputMenu{};
      int inputExit{};
      do {
         inputMenu = m_mainMenu.run();
         switch (inputMenu) {
         case 0:
            if (m_changed == false) {
               std::cout << std::endl;
               break;
            }
            else {
               inputExit = m_exitMenu.run();
               switch (inputExit) {
               case 0:
                  if (confirm("This will discard all the changes are you sure?")) {
                     m_changed = false;
                  }
                  break;
               case 1:
                  save();
                  break;
               case 2:
                  inputMenu = 1;
                  break;
               }
            }
            std::cout << std::endl;
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
      } while (inputMenu != 0);

      // Goodbye message
      std::cout << "-------------------------------------------" << std::endl;
      std::cout << "Thanks for using Seneca Library Application" << std::endl;
   }

   // Added Function for Milestone 5
   Publication* LibApp::getPub(int libRef) {
      Publication* ret{};
      for (int i = 0; !ret && i < m_nolp; i++) {
         if (libRef == m_ppa[i]->getRef()) {
            ret = m_ppa[i];
         }
      }
      return ret;
   }

   // Destructor
   LibApp::~LibApp() {
      for (int i = 0; i < m_nolp; i++) {
         delete m_ppa[i];
         m_ppa[i] = nullptr;
      }
   }

   LibApp::LibApp(const char filename[256]) : m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_pubMenu("Choose the type of publication:") {
      m_changed = false;

      // Populating main menu
      m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";

      // Populating exit menu
      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

      strcpy(m_filename, filename);
      m_nolp = 0;
      m_llrn = 0;

      m_pubMenu << "Book" << "Publication";

      load();
   }

}