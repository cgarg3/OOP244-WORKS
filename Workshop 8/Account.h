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

#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

#include "iAccount.h"

namespace sdds {
   class Account : public iAccount {
   private:
      double currBalance;
   protected:
      //  Returns the current balance of the account
      double balance() const;

   public:
      // Initializes current bank balance
      Account(double);

      // Returns success of credit transaction
      virtual bool credit(double);

      // Returns success of the debit transaction
      virtual bool debit(double);
   };
}

#endif