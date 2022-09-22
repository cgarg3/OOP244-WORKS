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

#include "Account.h"
#include <iostream>

namespace sdds {
   //  Returns the current balance of the account
   double Account::balance() const {
      return currBalance;
   }

   // Initializes current bank balance
   Account::Account(double amount) {
      if (amount < 0) {
         currBalance = 0.0;
      }
      else {
         currBalance = amount;
      }
   }

   // Returns success of credit transaction
   bool Account::credit(double amount) {
      bool success = false;
      if (amount > 0) {
         currBalance += amount;
         success = true;
      }

      return success;
   }

   // Returns success of the debit transaction
   bool Account::debit(double amount) {
      bool success = false;
      if (amount > 0) {
         currBalance -= amount;
         success = true;
      }

      return success;
   }
}