//
//  newSet.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/12/21.
//

#include "newSet.h"

Set::Set(int maximum): setSize(0), maxDistinctItems(maximum){
    if (maximum < 0) {
        std::exit(1);
    }
    setItems = new ItemType[maxDistinctItems];
}

Set::~Set() {

    delete[] setItems;
}

Set::Set(const Set& other) {
    setSize = other.setSize;
    maxDistinctItems = other.maxDistinctItems;
    setItems = new ItemType[maxDistinctItems];
    for (int i = 0; i < setSize; i++) {
        setItems[i] = other.setItems[i];
    }
}

Set& Set::operator=(const Set& rhs) {
    if (this != &rhs) {
        Set temp(rhs);
        swap(temp);
    }
    return *this;
}

bool Set::empty() const {
    // will return true if setSize is 0, false if not
    return (setSize == 0);
}

int Set::size() const {
    return setSize;
}

bool Set::insert(const ItemType& value) {
    bool isPresent = false;
    // return false if set already has a fixed capacity & is ffull
    if (setSize == maxDistinctItems) {
        return false;
    }
    // checks to see if value is already present
    for (int i = 0; i < setSize; i++) {
        if (value == setItems[i]) {
            isPresent = true;
            return false;
        }
    }
    // if value is not present, insert value at proper location and return true
    if (!isPresent) {
        int i;
        for (i = 0; i < setSize; i++) {
            // shift set to the right when value becomes greater than the current location of i
            if (value > setItems[i]) {
                for(int j = setSize; j > i; j--) {
                    setItems[j] = setItems[j-1];
                }
                // once shift is done, no need to keep looping thru Set
                break;
            }
        }
        // insert i in the correct location
        setItems[i] = value;
        // increse the size of the set
        setSize++;
        return true;
    }
    // default return statement
    return false;
}

bool Set::erase(const ItemType& value) {
    int i = 0;
    // start checking for identical value
    for (i = 0; i < setSize; i++) {
        // if value is equivalent, remove it, and shift everything else left to avoid empty space in set
        if (value == setItems[i]) {
            // shifting for loop, starting at where we left off for i
            for (; i < (setSize-1); i++) {
                setItems[i] = setItems[i+1];
            }
            // don't forget to reduce set size
            setSize--;
            return true;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const {
    // Return true if the value is in the set, otherwise false.
    bool isPresent = false;
    for (int i = 0; i < setSize; i++) {
        if (value == setItems[i]) {
            isPresent = true;
            break;
        }
    }
    return isPresent;
}

bool Set::get(int i, ItemType& value) const {
    bool isModified = false;
    if ((0 <= i) && (i < setSize)) {
        value = setItems[i];
        isModified = true;
    }
    return isModified;
}
  // If 0 <= i < size(), copy into value the item in the set that is
  // strictly less than exactly i items in the set and return true.
  // Otherwise, leave value unchanged and return false.
// specs indicate descending set?

void Set::swap(Set& other) {
/*
 Change the implementation of the swap function so that the number of statement executions when swapping two sets is the same no matter how many items are in the sets. (You would not satisfy this requirement if, for example, your swap function caused a loop to visit each item in the sets, since the number of statements executed by all the iterations of the loop would depend on the number of items in the sets.)
 */
    int tempSetSize = setSize;
    setSize = other.setSize;
    other.setSize =  tempSetSize;

    int tempMaxDistinctItems = maxDistinctItems;
    maxDistinctItems = other.maxDistinctItems;
    other.maxDistinctItems = tempMaxDistinctItems;

    ItemType *tempSetItems = setItems;
    setItems = other.setItems;
    other.setItems = tempSetItems;
}
  // Exchange the contents of this set with the other one.

