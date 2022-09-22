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

#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

namespace sdds {
   // This function stores the rate
   SavingsAccount::SavingsAccount(double initialBalance, double interestRate) : Account(initialBalance) {
      if (interestRate > 0) {
         this->interestRate = interestRate;
      }
      else {
         this->interestRate = 0.0;
      }
   }

   // This modifier calculates the interest earned on the current balance and credits the account with that interest
   void SavingsAccount::monthEnd() {
      double interestEarned = 0;

      // Calculating the interest earned
      interestEarned = (Account::balance() * interestRate);
      Account::credit(interestEarned);
   }

   // Receives a reference to an ostream object and inserts the following output on separate lines to the object.
   void SavingsAccount::display(std::ostream& os) const {
      os << "Account type: Savings" << std::endl;
      os << "Balance: $" << std::setprecision(2) << std::fixed << Account::balance() << std::endl;
      os << "Interest Rate (%): " << std::setprecision(2) << std::fixed << interestRate * 100 << std::endl;
   }
}