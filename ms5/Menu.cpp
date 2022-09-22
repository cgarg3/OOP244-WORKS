#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"

using namespace std;

namespace sdds {

   // Constructor
   MenuItem::MenuItem() {
      m_content = nullptr;
   }

   MenuItem::MenuItem(const char* content) {

      if (content != nullptr) {
         delete[] m_content;
         m_content = nullptr;
         m_content = new char[strlen(content) + 1];
         strcpy(m_content, content);
      }
      else {
         m_content = nullptr;
      }
   }

   // Destructor
   MenuItem::~MenuItem() {
      delete[] m_content;
      m_content = nullptr;
   }

   // Cast to bool
   MenuItem::operator bool()const {
      bool done = false;
      if (m_content != nullptr) {
         done = true;
      }
      return done;
   }

   // Cast to const char*
   MenuItem::operator const char* ()const {
      return m_content;
   }

   // Display
   ostream& MenuItem::display(ostream& os)const {
      if (m_content != nullptr) {
         os << m_content;
      }
      else {
         os << "";
      }
      return os;
   }

   // ------------------ Menu Class ---------------------------
   // Constructor
   Menu::Menu() {
      m_title = nullptr;
      m_numOfItems = 0;
   }

   Menu::Menu(const char* title) {
      if (title != nullptr && title[0] != '\0') {
         deallocate();
         m_title = new char[strlen(title) + 1];
         strcpy(m_title, title);
      }
      else {
         m_title = nullptr;
      }
   }

   // Destructor
   Menu::~Menu() {
      deallocate();
      for (int i = 0; i < m_numOfItems; i++) {
         delete m_menuItems[i];
         m_menuItems[i] = nullptr;
      }
   }

   // Deallocator
   void Menu::deallocate() {
      delete[] m_title;
      m_title = nullptr;
   }

   // Display title of menu
   void Menu::display() {
      if (m_title != nullptr) {
         cout << m_title << endl; // removed the :
      }
      for (int i = 0; i < m_numOfItems; i++) {
         cout << " " << i + 1 << "- " << m_menuItems[i]->m_content << endl;
      }
      cout << " 0- Exit" << endl;
      cout << "> ";
   }

   // Display Menu and get user selection
   int Menu::run() {
      display();

      char ch;
      cin >> ch;
      cin.ignore(); // added for milestone 5
      int input = ch - '0';

      while (input < 0 || input > m_numOfItems) {
         cin.clear();
         cin.ignore(80, '\n');
         cout << "Invalid Selection, try again: ";
         cin >> ch;
         cin.ignore();
         input = ch - '0';
      }
      return input;
   }

   // -------------- Overload Operator -----------------
   // Same as run function
   int Menu::operator~() {
      display();

      char ch;
      cin >> ch;
      int input = ch - '0';

      while (input < 0 || input > m_numOfItems) {
         cin.clear();
         cin.ignore(80, '\n');
         cout << "Invalid Selection, try again: ";
         cin >> ch;
         input = ch - '0';
      }
      return input;
   }

   // Add MenuItem to Menu
   Menu& Menu::operator<<(const char* menuitemConent) {
      m_menuItems[m_numOfItems++] = new MenuItem(menuitemConent);
      return *this;
   }

   // Return number of MenuItems on the Menu
   Menu::operator int()const {
      return m_numOfItems;
   }

   Menu::operator unsigned int()const {
      unsigned int items{};
      if (m_numOfItems >= 0) {
         items = m_numOfItems;
      }
      return items;
   }

   // True if one or more MenuItems in Menu
   Menu::operator bool()const {
      bool done = false;
      if (m_title != nullptr && m_menuItems != nullptr && m_numOfItems >= 0) {
         done = true;
      }
      return done;
   }

   const char* Menu::operator[](int index)const {
      return m_menuItems[index]->m_content;
   }

   ostream& Menu::write(ostream& os)const {
      if (m_title != nullptr) {
         os << m_title;
      }
      return os;
   }
   // Helper Function
   ostream& operator<<(ostream& os, const Menu& rhs) {
      return rhs.write(os);
   }

}