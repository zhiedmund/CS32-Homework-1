//
//  newSet.hpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#ifndef newSet_h
#define newSet_h

#include <iostream>

using ItemType = std::string;
//using ItemType = unsigned long;
const int DEFAULT_MAX_ITEMS = 150;

class Set
{
  public:
    Set(int maximum = DEFAULT_MAX_ITEMS);         // Create an empty set (i.e., one with no items).
    // int maximum is max distinct items by default if no value is included
    //destructor
    ~Set();
    //copy constructor
    Set(const Set& other);
    //assignment operator
    Set& operator=(const Set& rhs);

    bool empty() const;  // Return true if the set is empty, otherwise false.

    int size() const;    // Return the number of items in the set.

    bool insert(const ItemType& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value is actually inserted.  Leave the set unchanged
      // and return false if the value is not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const ItemType& value);
      // Remove the value from the set if it is present.  Return true if the
      // value was removed; otherwise, leave the set unchanged and
      // return false.

    bool contains(const ItemType& value) const;
      // Return true if the value is in the set, otherwise false.

    bool get(int i, ItemType& value) const;
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly less than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
      // Exchange the contents of this set with the other one.
private:
    // created int to help empty() and size()
    int setSize;
    // this pointer helps create a dynamically allocated array
    ItemType *setItems;
    // create int to track capacity for distinct items;
    int maxDistinctItems;

};

#endif /* newSet_h */
