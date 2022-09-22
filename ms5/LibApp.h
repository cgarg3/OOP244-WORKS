#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"
#include "Publication.h"

namespace sdds {
   class LibApp {
      bool m_changed{};
      char m_filename[256 + 1]{};
      int m_nolp{};
      int m_llrn{};
      Publication* m_ppa[SDDS_LIBRARY_CAPACITY];
      Menu m_mainMenu{};
      Menu m_exitMenu{};
      Menu m_pubMenu{};

      bool confirm(const char* message);
      void load();
      void save();
      int search(bool checkOut, bool onLoan);
      void returnPub();

      // Methods with confirmation
      void newPublication();
      void removePublication();
      void checkOutPub();

      Publication* getPub(int libRef);
   public:
      // Constructor
      LibApp();

      // Destructor
      ~LibApp();

      // Display main meny
      void run();

      LibApp(const char filename[256]);
   };
}
#endif // !SDDS_LIBAPP_H
