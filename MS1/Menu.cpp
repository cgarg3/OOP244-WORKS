/*
*****************************************************************************
                    Workshop - #MS!
Full Name  : CHIRAG GARG
Student ID#: 143180214
Email      : CGARG3@MYSENECA.CA
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
***
*/

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <iomanip>
//#include "Menu.h"
//
//using namespace std;
//
//namespace sdds
//{
//   // Constructor
//   MenuItem::MenuItem() {
//      m_menuitem = nullptr;
//   }
//
//   MenuItem::MenuItem(const char* menuItem) {
//
//      if (menuItem != nullptr) {
//         delete[] m_menuitem;
//         m_menuitem = nullptr;
//         m_menuitem = new char[strlen(menuItem) + 1];
//         strcpy(m_menuitem, menuItem);
//      }
//      else {
//         m_menuitem = nullptr;
//      }
//   }
//
//   MenuItem::~MenuItem() {
//      delete[] m_menuitem; // deletes each pointer up to the number of menu items in the menu.
//      m_menuitem = nullptr;
//   }
//
//   // Cast to bool
//   MenuItem::operator bool()const {
//      bool result = false;
//      if (m_menuitem != nullptr) {
//         result = true;
//      }
//      return result;
//   }
//
//   // Cast to const char*
//   MenuItem::operator const char* ()const {
//      return m_menuitem;
//   }
//
//   ostream& MenuItem::display(ostream& os) const {
//      if (m_menuitem != nullptr) {
//         cout << m_menuitem; //  to display the title of the Menu on ostream
//      }
//      else
//      {
//         os << "";
//      }
//      return os;
//   }
//
//   void Menu::setEmpty() {
//      m_title = nullptr;
//      ItemNum = 0;
//   }
//
//   Menu::Menu() {
//      setEmpty();
//   }
//
//   Menu::Menu(const char* ttl) {
//      if (ttl != nullptr && ttl[0] != '\0') {
//         delete[] m_title;
//         m_title = nullptr;
//         m_title = new char[strlen(ttl) + 1];
//         strcpy(m_title, ttl);
//      }
//      else {
//         m_title = nullptr;
//      }
//   }
//
//   // destructor
//   Menu::~Menu() {
//      delete[] m_title;
//      m_title = nullptr;
//      for (int i = 0; i < ItemNum; i++) {
//         delete MenuItems[i];
//         MenuItems[i] = nullptr;
//      }
//   }
//
//   void Menu::display()
//   {
//      if (m_title != nullptr) {
//         cout << m_title << ":" << endl;
//      }
//      for (int i = 0; i < ItemNum; i++) {
//         cout << " " << i + 1 << "- " << MenuItems[i]->m_menuitem << endl;
//      }
//      cout << " 0- Exit" << endl;
//      cout << "> ";
//      
//   }
//
//   unsigned int Menu::run() {
//      int selection = -1;
//      display();
//      cin >> selection;
//      if (cin.fail())
//      {
//         do
//         {
//            cin.clear();
//            cin.ignore(1024, '\n');
//            cout << "Invalid Selection, try again: ";
//            cin >> selection;
//         } while (cin.fail() || selection < 0 || selection > ItemNum);
//      }
//      else
//      {
//         if (selection < 0 || selection > ItemNum)
//         {
//            do
//            {
//               cin.clear();
//               cin.ignore(1024, '\n');
//               cout << "Invalid Selection, try again: ";
//               cin >> selection;
//            } while (cin.fail() || selection < 0 || selection > ItemNum);
//         }
//      }
//      cin.clear();
//      return selection;
//   }
//
//   unsigned int Menu::operator~()
//   {
//      int selection = -1;
//      display();
//      cin >> selection;
//      if (cin.fail())
//      {
//         do
//         {
//            cin.clear();
//            cin.ignore(1024, '\n');
//            cout << "Invalid Selection, try again: ";
//            cin >> selection;
//         } while (cin.fail() || selection < 0 || selection > ItemNum);
//      }
//      else
//      {
//         if (selection < 0 || selection > ItemNum)
//         {
//            do
//            {
//               cin.clear();
//               cin.ignore(1024, '\n');
//               cout << "Invalid Selection, try again: ";
//               cin >> selection;
//            } while (cin.fail() || selection < 0 || selection > ItemNum);
//         }
//      }
//      cin.clear();
//      return selection;
//   }
//
//   Menu& Menu::operator<<(const char* item) {
//      MenuItems[ItemNum++] = new MenuItem(item);
//      return *this;
//   }
//
//   Menu::operator int() const {
//      return ItemNum;
//   }
//
//   Menu::operator unsigned int() const
//   {
//      unsigned int items{};
//      if (ItemNum >= 0) {
//         items = ItemNum;
//      }
//      return items;
//   }
//
//   Menu::operator bool() const {
//      bool result = false;
//      if (m_title != nullptr && MenuItems != nullptr && ItemNum >= 0) {
//         result = true;
//      }
//      return result;
//   }
//
//   const char* Menu::operator[](int index) const
//   {
//      return MenuItems[index]->m_menuitem;
//   }
//
//   std::ostream& Menu::write(std::ostream& os) const
//   {
//      if (m_title != nullptr) {
//         os << m_title;
//      }
//      return os;
//   }
//
//   ostream& operator<<(ostream& os, const Menu& rhs)
//   {
//      return rhs.write(os);
//   }
//}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Utils.h"
#include "Menu.h"



namespace sdds
{
   // --------------------
   // MenuItem Class
   // --------------------

   MenuItem::MenuItem() {
      setEmpty();
   }

   MenuItem::MenuItem(const char* textContent) {
      if (textContent && textContent[0]) {
         menuContent = new char[strlen(textContent) + 1];
         strcpy(menuContent, textContent);
      }
      else {
         setEmpty();
      }
   }

   MenuItem::~MenuItem() {
      delete[] menuContent;
   }

   // Sets a MenuItem object to safe empty
   void MenuItem::setEmpty() {
      menuContent = nullptr;
   }

   // Return true, if it is not empty and it should return false if it is empty
   MenuItem::operator bool() const {
      return (menuContent && menuContent[0]);
   };

   // Should return the address of the content Cstring.
   MenuItem::operator const char* () const {
      return menuContent;
   }

   // Display the content of the MenuItem on ostream
   std::ostream& MenuItem::display(std::ostream& os)const {
      if (*this) {
         os << menuContent;
      }

      return os;
   }

   // --------------------
   // Menu Class
   // --------------------

   Menu::Menu() {
      pointerCount = 0;
   };

   Menu::Menu(const char* title) : menuTitle(title) {};

   Menu::~Menu() {
      unsigned int i;
      for (i = 0; i < MAX_MENU_ITEMS; i++)
      {
         delete menuItems[i];
      }
   };

   // Function to display the title of the menu
   std::ostream& Menu::displayMenuTitle(std::ostream& os)const {
      if (menuTitle) {
         menuTitle.display();
      }

      return os;
   }
   // Display the content of Menu on ostream
   std::ostream& Menu::displayMenu(std::ostream& os)const {
      if (menuTitle)
      {
         menuTitle.display();
         os << ":" << std::endl;
      }

      int i;
      for (i = 0; i < pointerCount; i++)
      {
         os.width(2);
         os.setf(std::ios::right);
         os.fill(' ');
         os << i + 1 << "- ";
         os.unsetf(std::ios::right);
         menuItems[i]->display(os);
         os << std::endl;
      }
      os << " 0- Exit" << std::endl;
      os << "> ";

      return os;
   }

   // Return the number of MenuItems on the Menu.
   Menu::operator int() {
      return pointerCount;
   }

   // Return the number of MenuItems on the Menu.
   Menu::operator unsigned int()const {
      return pointerCount;
   }

   // Return true if the Menu has one or more MenuItems otherwise, false;
   Menu::operator bool()const {
      return (pointerCount > 0);
   }

   // Overloading the insertion operator
   std::ostream& operator<<(std::ostream& os,  const Menu& menu) {
      return menu.displayMenuTitle(os);
   }

   // Displays the Menu and gets the user selection.
   unsigned int Menu::run() {
      int user_input;
      displayMenu();
      user_input = getIntegerInput(0, pointerCount);
      return user_input;
   }

   // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
  unsigned int Menu::operator~() {
      return run();
   }

   // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
   Menu& Menu::operator<<(const char* menuitemContent) {
      if (pointerCount < MAX_MENU_ITEMS)
      {
         MenuItem* newMenuItem = new MenuItem(menuitemContent);
         menuItems[pointerCount] = newMenuItem;
         pointerCount++;
      }

      return *this;
   }

   // If the index passes the number of MenuItems in the Menu, loop back to the beginning.
   const char* Menu::operator[]( int index) const {
      if (index > pointerCount)
      {
         return menuItems[index %= pointerCount]->menuContent;
      }
      else
      {
         return menuItems[index]->menuContent;
      }
   }
};