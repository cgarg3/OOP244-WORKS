#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
   // Insertion and Extraction operator overloads
   std::ostream& operator<<(std::ostream& os, const Streamable& s) {
      // Object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state
      if (s) {
         s.write(os);
      }
      return os;
   }
   std::istream& operator>>(std::istream& is, Streamable& s) {
      return (s.read(is));
   }
}