#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "Publication.h"

namespace sdds {
   class Book : public Publication {
      char* m_authorName{};
   public:
      //Constructor
      Book();

      // The rule of three
      Book(const Book& book);
      Book& operator=(const Book& book);
      ~Book();
      void deallocate();

      // ----------------- Methods -----------------------
      char type()const;
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      virtual void set(int member_id);
      operator bool() const;
   };
}
#endif // !SDDS_BOOK_H
