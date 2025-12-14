#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

template <typename T> class ArrayList{
    T* data;
    int max;
    int length;
    public:
        ArrayList();

        bool insert(int, const T&);
        bool insert(const T&);
        bool remove(int);
        T get(int) const;
        T* getAll() const;
        int size() const;
        bool isEmpty() const;
        void print() const;
        void clear() const;

        T& operator[](int);
};
#include "arraylist.cpp"
#endif