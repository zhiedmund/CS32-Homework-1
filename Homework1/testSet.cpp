//
//  testSet.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#include "Set.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void testCase1() {
    Set s;
    assert(s.empty());
    ItemType x = "arepa";
    assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
    s.insert("chapati");
    assert(s.size() == 1);
    assert(s.get(0, x)  &&  x == "chapati");

}

void testCase2() {
    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    string x;
    ss.get(0, x);
    assert(x == "roti");  // "roti" is less than exactly 4 items in ss
    ss.get(4, x);
    assert(x == "chapati");  // "chapati" is less than exactly 0 items in ss
    ss.get(2, x);
    assert(x == "lavash");  // "lavash" is less than exactly 2 items in ss
    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
           ss2.size() == 1  &&  ss2.contains("laobing"));
}

void testCase3() {
    Set ss;
    ss.insert("dosa");
    assert(!ss.contains(""));
    ss.insert("tortilla");
    ss.insert("");
    ss.insert("focaccia");
    assert(ss.contains(""));
    ss.erase("dosa");
    assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("tortilla")  &&
                ss.contains(""));
    string v;
    assert(ss.get(1, v)  &&  v == "focaccia");
    assert(ss.get(2, v)  &&  v == "");
}

void testCase4() {
    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    string x;
    ss.get(0, x);
    assert(x == "roti");  // "roti" is less than exactly 4 items in ss
    ss.get(4, x);
    assert(x == "chapati");  // "chapati" is less than exactly 0 items in ss
    ss.get(2, x);
    assert(x == "lavash");  // "lavash" is less than exactly 2 items in ss
}

void testCase5() {
    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
           ss2.size() == 1  &&  ss2.contains("laobing"));

}

void testCase6() {
    Set ss;
    ss.insert("dosa");
    assert(!ss.contains(""));
    ss.insert("tortilla");
    ss.insert("");
    ss.insert("focaccia");
    assert(ss.contains(""));
    ss.erase("dosa");
    assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("tortilla")  &&
                ss.contains(""));
    string v;
    assert(ss.get(1, v)  &&  v == "focaccia");
    assert(ss.get(2, v)  &&  v == "");
}
int main()
{
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
    cerr << "Passed all tests" << endl;


}
