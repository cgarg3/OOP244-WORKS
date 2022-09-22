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

#include "Basket.h"

namespace sdds
{
   // default constructor
   Basket::Basket() = default;

   // store the values (custom constructor)
   Basket::Basket(Fruit* fruits, int cnt, double price)
   {
      if (fruits && cnt > 0)
      {
         m_cnt = cnt;
         m_price = price;
         m_fruits = new Fruit[m_cnt];
         for (int i = 0; i < m_cnt; i++)
         {
            m_fruits[i] = fruits[i];
         }
      }
   }

   Basket::Basket(const Basket& obj)
   {
      *this = obj;
   }
   Basket& Basket::operator=(const Basket& obj)
   {
      if (this != &obj)
      {

         delete[] m_fruits;
         m_fruits = nullptr;
         m_cnt = 0;
         m_price = 0;
         if (obj.m_fruits && obj.m_cnt > 0)
         {
            m_cnt = obj.m_cnt;
            m_price = obj.m_price;
            m_fruits = new Fruit[m_cnt];
            for (int i = 0; i < m_cnt; i++) {
               m_fruits[i] = obj.m_fruits[i];
            }
         }
      }
      return *this;
   }

   Basket::~Basket()
   {
      delete[] m_fruits;
   }
   
   void Basket::setPrice(double price)
   {
      m_price = price > 0 ? price : m_price;
   }
   Basket::operator bool() const
   {
      return m_cnt > 0;
   }
   Basket& Basket::operator+=(const Fruit F)
   {
      Fruit* tempArray = new Fruit[m_cnt + 1];
      for (int i = 0; i < m_cnt; i++)
      {
         tempArray[i] = m_fruits[i];
      }
      tempArray[m_cnt] = F;
      delete[] m_fruits;
      m_fruits = tempArray;
      m_cnt++;
      return *this;
   }
   std::ostream& Basket::display(std::ostream& ostr) const
   {
      if (operator bool())
      {

         ostr << "Basket Content:" << std::endl;
         for (int i = 0; i < m_cnt; i++)
         {
            ostr.setf(std::ios::right);
            ostr.width(10);
            ostr << m_fruits[i].m_name << ": ";
            ostr.unsetf(std::ios::right);
            ostr.setf(std::ios::fixed);
            ostr.precision(2);
            ostr << m_fruits[i].m_qty << "kg" << std::endl;
            ostr.unsetf(std::ios::fixed);
         }
         ostr << "Price: ";
         ostr.setf(std::ios::fixed);
         ostr.precision(2);
         ostr << m_price;
         ostr.unsetf(std::ios::fixed);
         ostr << std::endl;
      }

      else
      {
         ostr << "The basket is empty!" << std::endl;
      }
      return ostr;
   }
   std::ostream& operator<<(std::ostream& ostr, const Basket& B)
   {
      return B.display(ostr);
   }
}