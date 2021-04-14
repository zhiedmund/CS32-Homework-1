//
//  AccountSet.hpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#ifndef AccountSet_h
#define AccountSet_h

#include <stdio.h>
#include "Set.h"

class AccountSet {
public:
    AccountSet();  // Create an empty account set.

    bool add(unsigned long acctNum);
      // Add an account number to the AccountSet.  Return true if and
      // only if the account number was actually added.

    int size() const;
      // Return the number of account numbers in the AccountSet.

    void print() const;
      // Write to cout every account number in the AccountSet exactly
      // once, one per line.  Write no other text.

private:
    Set m_account;
};


#endif /* AccountSet_h */
