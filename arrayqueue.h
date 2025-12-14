#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
using namespace std;

template <typename T> class ArrayQueue{
    T* data;
    int max;
    int length;
    public:
        ArrayQueue();

        bool enqueue(const T&);
        T dequeue();
        T peek() const;
        bool isEmpty() const;
        void print() const;
};
#include "arrayqueue.cpp"
#endif