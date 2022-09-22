/*
*****************************************************************************
						  Workshop - #6 (P2)
Full Name  : CHIRAG GARG
Student ID#: 143180214
Email      : CGARG3@MYSENECA.CA
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H
#include <iostream>

namespace sdds
{
   struct Fruit
   {
      char m_name[31];
      double m_qty;
   };
   class Basket
   {
      Fruit* m_fruits{};
      int m_cnt{};
      double m_price{};

   public:
      Basket();
      Basket(Fruit* fruits, int cnt, double price);
      Basket(const Basket& obj);
      Basket& operator=(const Basket& obj);
      ~Basket();
      void setPrice(double price);
      operator bool() const;
      Basket& operator+=(const Fruit F);
      std::ostream& display(std::ostream& ostr = std::cout) const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Basket& B);

}

#endif // !SDDS_BASKET_H