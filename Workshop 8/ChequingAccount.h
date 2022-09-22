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

#ifndef SDDS_CHEQUINGACCOUNT_H
#define SDDS_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sdds {
   class ChequingAccount : public Account {
   private:
      double transactionFee;
      double monthlyFee;
   public:
      // This function stores the fee
      ChequingAccount(double, double, double);

      // This modifier credits the balance by the amount received and if successful debits the transaction fee from the balance
      bool credit(double);

      // This modifier debits the balance by the amount received and if successful debits the transaction fee from the balance
      bool debit(double);

      // This modifier debits the monthly fee from the balance, but does not charge a transaction fee for this debit
      void monthEnd();

      // Receives a reference to an ostream object and inserts the following output on separate lines to the object
      void display(std::ostream&) const;
   };
}

#endif