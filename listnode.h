#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

template <typename T> class ListNode{
    ListNode* next;
    T value;
    public:
        ListNode();
        ListNode(const ListNode<T>&);
        ListNode(ListNode<T>*, T);

        ListNode* getNext();
        T getValue();

        void setNext(ListNode*);
        void setValue(T);

        ListNode<T>& operator=(const ListNode<T>&);
};
#include "listnode.cpp"
#endif