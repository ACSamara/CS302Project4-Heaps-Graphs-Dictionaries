#ifndef DICTIONARY_H
#define DICTIONARY_H

// Small hash table for assignment purposes
// Can be changed to any prime number
#define TABLE_SIZE 5

#include "building.h"
#include "linkedlist.h"

template <typename T> class Dictionary{
    LinkedList<T> hashTable[TABLE_SIZE];
    int numEntries;
    
    // Private functions
    int h(string);

    public:
        Dictionary();

        bool insert(string key, T value);
        bool remove(string key);
        T get(string key);
        bool contains(string key);

        T operator[](string key);
};
#include "dictionary.cpp"
#endif