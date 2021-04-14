//
//  AccountSet.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//
#include <iostream>
#include "AccountSet.h"
using namespace std;

AccountSet::AccountSet(): m_account() {
}

bool AccountSet::add(unsigned long acctNum) {
    // Add an account number to the AccountSet.  Return true if and
    // only if the account number was actually added.
    return m_account.insert(acctNum);
}

int AccountSet::size() const {
    return m_account.size();
    // Return the number of account numbers in the AccountSet.
}

void AccountSet::print() const {
    // Write to cout every account number in the AccountSet exactly
    // once, one per line.  Write no other text.
    ItemType item;
    for (int i = 0; i < m_account.size(); i++) {
        m_account.get(i, item);
        cout << item << endl;
    }
}

