/*
*****************************************************************************
						  Workshop - #8
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


#ifndef SDDS_SAVINGSACCOUNT_H
#define SDDS_SAVINGSACCOUNT_H

#include "Account.h"

namespace sdds {
   class SavingsAccount : public Account {
   private:
      double interestRate;
   public:
      // This function stores the rate
      SavingsAccount(double, double);

      // This modifier calculates the interest earned on the current balance and credits the account with that interest
      void monthEnd();

      // Receives a reference to an ostream object and inserts the following output on separate lines to the object.
      void display(std::ostream&) const;
   };
}

#endif