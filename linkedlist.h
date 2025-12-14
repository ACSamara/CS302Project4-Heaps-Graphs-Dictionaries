#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "listnode.h"
using namespace std;

template <typename T> class LinkedList{
    ListNode<T>* first;
    int length;
    public:
        LinkedList();

        bool insert(int, const T&);
        bool insert(const T&);
        bool remove(int);
        T get(int) const;
        int size() const;
        bool isEmpty() const;
        void print() const;

        T operator[](int) const;
};
#include "linkedlist.cpp"
#endif
