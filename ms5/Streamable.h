#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>
#include <iomanip>

namespace sdds {
   class Streamable {
   public:
      // Pure virtual function
      virtual std::ostream& write(std::ostream& os)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
      virtual bool conIO(std::ios& io)const = 0;
      virtual operator bool()const = 0;

      // Destructor
      virtual ~Streamable() {};

      //Insertion
      //virtual ostream& operator>>(Streamable) = 0;

      //Extraction
      //virtual istream& operator<<(Streamable) = 0;
   };
   // Helper function
   std::ostream& operator<<(std::ostream& os, const Streamable& rhs);
   std::istream& operator>>(std::istream& is, Streamable& rhs);

}
#endif // !SDDS_STREAMABLE_H
