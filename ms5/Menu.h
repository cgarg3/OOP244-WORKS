#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {
   const int MAX_MENU_ITEMS = 20;
   class Menu;
   class MenuItem {
      char* m_content{}; // dynamic - unknwn length

      // Constructor
      MenuItem();

      MenuItem(const char* content);


      // Rule of Three - delete copy
      MenuItem(const MenuItem& toCopy) = delete;
      MenuItem& operator=(const MenuItem& toAssign) = delete;

      // Destructor
      ~MenuItem();

      // Cast to bool
      operator bool()const;

      // Cast to const char*
      operator const char* ()const;

      // Display
      std::ostream& display(std::ostream& os)const;

      friend class Menu;
   };

   // ------------------ Menu Class ---------------------------
   class Menu {
      char* m_title{};
      MenuItem* m_menuItems[MAX_MENU_ITEMS]{}; // dynamic
      int m_numOfItems{}; // 0 to max

   public:
      // Constructor
      Menu();
      Menu(const char* title);

      // Rule of Three
      Menu(const Menu& toCopy) = delete;
      Menu& operator=(const Menu& toAssign) = delete;

      // Destructor
      ~Menu();

      // Deallocator
      void deallocate();

      // Display title of menu
      void display();

      // Display Menu and get user selection
      int run();

      // -------------- Overload Operator -----------------
      // Same as run function
      int operator~();

      // Add MenuItem to Menu
      Menu& operator<<(const char* menuitemConent);

      // Return number of MenuItems on the Menu
      operator int()const;
      operator unsigned int()const;

      // True if one or more MenuItems in Menu
      operator bool()const;

      const char* operator[](int index)const;

      std::ostream& write(std::ostream& os = std::cout)const;

   };
   // Helper function
   std::ostream& operator<<(std::ostream& os, const Menu& rhs);


}
#endif // !SDDS_MENU_H
