//
//  Set.cpp
//  Homework1
//
//  Created by Edmund Zhi on 4/11/21.
//

#include "Set.h"

Set::Set(): setSize(0){
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
    // return false if set already has a fixed capacity & is full
    if (setSize == DEFAULT_MAX_ITEMS) {
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
    // creates temporary array of current Set
    ItemType temp[DEFAULT_MAX_ITEMS];
    for (int i = 0; i < setSize; i++) {
        temp[i] = setItems[i];
    }

    ItemType item;
    int newSetSize = other.size();
    for(int i = 0; i < newSetSize; i++) {
        other.get(0, item);
        setItems[i] = item;
        other.erase(item);
    }

    for(int j = 0; j < setSize; j++) {
        other.insert(temp[j]);
    }
    setSize = newSetSize;

    // Implementation note: The swap function is easily implementable without creating any additional container of many items such as an additional array or an additional Set.

}
  // Exchange the contents of this set with the other one.

