#ifndef HEAP_H
#define HEAP_H

#include "helpers.h"

template <typename T> class Heap{
    T* data;
    int size, maxSize, depth;

    void maxHeapify(int);
    int getParent(int);
    int getLeft(int);
    int getRight(int);

    public:
        Heap();

        bool insert(T item);
        T extractMax();
        T peek();
        void buildMaxHeap(int, T*);
        bool isEmpty();
        void clear();

        int getDepth();

        void print();
};
#include "heap.cpp"
#endif