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

#ifndef SDDS_IACCOUNT_H
#define SDDS_IACCOUNT_H

#include <iostream>

namespace sdds {
   class iAccount {
   public:
      // Public empty virtual destructor
      virtual ~iAccount() {};

      // Adds a positive amount to the account balance
      virtual bool credit(double) = 0;

      // Subtracts a positive amount from the account balance
      virtual bool debit(double) = 0;

      // Applies month-end transactions to the account
      virtual void monthEnd() = 0;

      // Inserts account information into an ostream object
      virtual void display(std::ostream&) const = 0;
   };
   // Creates the account with the starting balance and returns its address.
   iAccount* CreateAccount(const char*, double);
}

#endif