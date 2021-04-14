//
//  testAccountSet.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#include <stdio.h>
#include <iostream>
#include <cassert>

#include "AccountSet.h"

using namespace std;

int main() {
    
    AccountSet account;
    account.add(1);
    assert(account.add(1) == false);
    account.add(4);
    account.add(2);
    assert(account.add(4) == false);
    assert(account.size() == 3);
    account.add(3);
    assert(account.size() == 4);
    cerr << "All test cases passed!" << endl;
    // prints 4, 3, 2, 1
    account.print();
}
