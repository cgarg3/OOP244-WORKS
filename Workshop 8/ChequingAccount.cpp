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

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>

namespace sdds {
   // This function stores the fee
   ChequingAccount::ChequingAccount(double initialBalance, double transactionFee, double monthlyFee) : Account(initialBalance) {
      // Validating the transaction fee
      if (transactionFee > 0) {
         this->transactionFee = transactionFee;
      }
      else {
         this->transactionFee = 0.0;
      }

      // Validating the monthly fee
      if (monthlyFee > 0) {
         this->monthlyFee = monthlyFee;
      }
      else {
         this->monthlyFee = 0.0;
      }
   }

   // This modifier credits the balance by the amount received and if successful debits the transaction fee from the balance
   bool ChequingAccount::credit(double amount) {
      bool success = false;
      if (Account::credit(amount) && Account::debit(transactionFee)) {
         success = true;
      }

      return success;
   }

   // This modifier debits the balance by the amount received and if successful debits the transaction fee from the balance
   bool ChequingAccount::debit(double amount) {
      bool success = false;
      if (Account::debit(amount) && Account::debit(transactionFee)) {
         success = true;
      }

      return success;
   }

   // This modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit
   void ChequingAccount::monthEnd() {
      Account::debit(monthlyFee);
   }

   // Receives a reference to an ostream object and inserts the following output on separate lines to the object
   void ChequingAccount::display(std::ostream& os) const {
      os << "Account type: Chequing" << std::endl;
      os << "Balance: $" << std::setprecision(2) << std::fixed << Account::balance() << std::endl;
      os << "Per Transaction Fee: " << std::setprecision(2) << std::fixed << transactionFee << std::endl;
      os << "Monthly Fee: " << std::setprecision(2) << std::fixed << monthlyFee << std::endl;
   }
}