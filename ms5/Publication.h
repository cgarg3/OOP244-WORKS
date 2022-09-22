#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
   class Publication : public Streamable {
      char* m_title{}; // hold dynamic title
      char m_shelfId[SDDS_SHELF_ID_LEN + 1]{}; // 4 char long hold location of publication
      int m_membership{}; //5 digit number - if 0 publication available, else it is checked out by a member
      int m_libRef{}; // default = -1 --> serial number to identify each publication uniquely
      Date m_date{}; // set to current date default

   public:
      // Constructor
      Publication();

      // Set default
      void setDefault();

      // The rule of three
      // Copy overload
      Publication(const Publication& publication);
      // Copy assignment
      Publication& operator=(const Publication& publication);
      // Destruction
      ~Publication();

      // Deallocator
      void deallocate();


      // ----------------- Methods -----------------------
      // Modifiers
      // Sets the membership attribute to either zero or a five-digit integer.
      virtual void set(int member_id);

      // Sets the **libRef** attribute value
      void setRef(int value);

      // Sets the date to the current date of the system.
      void resetDate();

      // Queries
      //Returns the character 'P' to identify this object as a "Publication object"
      virtual char type()const;

      //Returns true is the publication is checkout (membership is non-zero)
      Date checkoutDate()const;

      //Returns the date attribute
      bool onLoan()const;

      //Returns true if the argument title appears anywhere in the title of the 
      //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
      bool operator==(const char* title)const;

      //Returns the title attribute
      operator const char* ()const;

      //Returns the libRef attirbute. 
      int getRef()const;

      // Streamable pure virtual function
      virtual bool conIO(std::ios& io)const;
      virtual std::ostream& write(std::ostream& os) const;
      virtual std::istream& read(std::istream& istr);
      virtual operator bool() const;
   };
}
#endif // !SDDS_PUBLICATION_H
