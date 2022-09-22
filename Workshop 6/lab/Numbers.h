/*
*****************************************************************************
						  Workshop - #6 (P1)
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

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
   class Numbers
   {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();

      // Copy Constructor
      Numbers(const Numbers& obj);

      // Copy Assignment Contructor
      Numbers& operator=(const Numbers& obj);

      // Member functions
      int numberCount() const;
      bool load();
      void save();
      Numbers& operator+=(double value);

      // display functions
      std::ostream& display(std::ostream& ostr)const;
   };

   //Insertion operator
   std::ostream& operator<<(std::ostream& ostr, const Numbers& N);
   
   //Extraction operator
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_


