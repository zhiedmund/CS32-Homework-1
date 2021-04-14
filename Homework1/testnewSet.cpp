//
//  testnewSet.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#include "newSet.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Set ss;
    assert(ss.insert("pita"));
    assert(ss.insert("roti"));
    assert(ss.size() == 2);
    assert(ss.contains("roti"));
    ItemType x = "laobing";
    assert(ss.get(0, x)  &&  x == "roti");
    assert(ss.get(1, x)  &&  x == "pita");
}

//void test()
//{
//    Set uls;
//    assert(uls.insert(10));
//    assert(uls.insert(20));
//    assert(uls.size() == 2);
//    assert(uls.contains(20));
//    ItemType x = 30;
//    assert(uls.get(0, x)  &&  x == 20);
//    assert(uls.get(1, x)  &&  x == 10);
//}

void test2() {
    Set a(1000);   // a can hold at most 1000 distinct items
     Set b(5);      // b can hold at most 5 distinct items
     Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
     ItemType v[6] = { "1", "2","3","4","5","6" };

       // No failures inserting 5 distinct items into b
     for (int k = 0; k < 5; k++)
         assert(b.insert(v[k]));

       // Failure if we try to insert a sixth distinct item into b
     assert(!b.insert(v[5]));

       // When two Sets' contents are swapped, their capacities are swapped
       // as well:
     a.swap(b);
     assert(!a.insert(v[5])  &&  b.insert(v[5]));
}


int main()
{
    test();
    test2();
    cerr << "Passed all tests" << endl;
}

