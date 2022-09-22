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

//#ifndef SDDS_MENU_H__
//#define SDDS_MENU_H__
//
//
//namespace sdds
//{
//	const int MAX_MENU_ITEMS = 20;
//	class Menu; // forward declaration
//	class MenuItem
//	{
//		char* m_menuitem{}; // holds only one Cstring of characters for the content of the menu item dynamically
//
//		MenuItem(); // constructor
//		MenuItem(const char* item);
//
//
//		//copy constructors and assignments (rule of three)
//		MenuItem(const MenuItem& itemSrc) = delete;
//		MenuItem& operator=(const MenuItem& itemSrc) = delete;
//
//		~MenuItem();
//
//		// Cast to bool
//		operator bool()const;
//
//		// Cast to const char*
//		operator const char* ()const;
//
//		// display
//		std::ostream& display(std::ostream& os) const;
//
//		friend class Menu; // makes MenuItem class only accessible by the Menu class
//	};
//
//	class Menu
//	{
//		char* m_title{};
//		MenuItem* MenuItems[MAX_MENU_ITEMS]{};
//		int ItemNum{};
//	public:
//
//		void setEmpty();
//		// constructor
//		Menu();
//		Menu(const char* ttl);
//
//		// rule of three (copy assignment and constructor)
//		Menu(const Menu& menuSrc) = delete;
//		Menu& operator=(const Menu& menuSrc) = delete;
//
//		// destructor
//		~Menu();
//
//		// Display title of menu
//		void display();
//
//		// Display Menu and get user selection
//		unsigned int run();
//		unsigned int operator~();
//
//		// Add MenuItem to Menu
//		Menu& operator<<(const char* item);
//
//		// Return number of MenuItems on the Menu
//		operator int() const;
//		operator unsigned int() const;
//
//		// True if one or more MenuItems in Menu
//		operator bool() const;
//
//		const char* operator[](int index)const;
//
//		std::ostream& write(std::ostream& os = std::cout)const;
//	};
//
//	// Helper function
//	std::ostream& operator<<(std::ostream& os, const Menu& rhs);
//}
//#endif



#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
   const unsigned int  MAX_MENU_ITEMS = 20;

   class MenuItem
   {
   private:
      // Holds only one Cstring of characters for the content of the menu item dynamically.
      char* menuContent{};

      MenuItem();
      MenuItem(const char* textContent);
      ~MenuItem();

      // Copying is not allowed
      MenuItem(const MenuItem& menuItem) = delete;
      void operator=(const MenuItem& MI) = delete;

      // Sets a MenuItem object to safe empty
      void setEmpty();

      // Return true, if it is not empty and it should return false if it is empty
      operator bool() const;

      // Should return the address of the content Cstring.
      operator const char* () const;

      // Display the content of the MenuItem on ostream
      std::ostream& display(std::ostream& os = std::cout)const;

      friend class Menu;
   };

   class Menu
   {
   private:
      MenuItem menuTitle{};
      MenuItem* menuItems[MAX_MENU_ITEMS]{};
      int pointerCount = 0;

   public:
      Menu();
      Menu(const char* title);
      ~Menu();

      // Copying is not allowed
      Menu(const Menu& M) = delete;
      void operator=(const Menu& M) = delete;

      // Function to display the title of the menu
      std::ostream& displayMenuTitle(std::ostream& os)const;

      // Display the content of Menu on ostream
      std::ostream& displayMenu(std::ostream& os = std::cout)const;

      // Return the number of MenuItems on the Menu.
      operator int();

      // Return the number of MenuItems on the Menu.
      operator unsigned int() const;

      // Return true if the Menu has one or more MenuItems otherwise, false;
      operator bool()const;

      // Displays the Menu and gets the user selection.
     unsigned int run();

      // Overload operator~ to do exactly what the run function does (two different ways to run the menu)
      unsigned int operator~();

      // Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
      Menu& operator<<(const char* menuitemContent);

      // If the index passes the number of MenuItems in the Menu, loop back to the beginning.
      const char* operator[](int index) const;
   };
   // Overloading the insertion operator
   std::ostream& operator<<(std::ostream& os, const Menu& menu);
}

#endif