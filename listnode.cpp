#include "listnode.h"

template <class T>
ListNode<T>::ListNode(){
    next = nullptr;
}
template <class T>
ListNode<T>::ListNode(const ListNode<T>& rhs){
    next = rhs.next;
    value = rhs.value;
}
template <class T>
ListNode<T>::ListNode(ListNode<T>* n, T v){
    next = n;
    value = v;
}
template <class T>
ListNode<T>* ListNode<T>::getNext(){
    return next;
}
template <class T>
T ListNode<T>::getValue(){
    return value;
}
template <class T>
void ListNode<T>::setNext(ListNode* n){
    next = n;
}
template <class T>
void ListNode<T>::setValue(T v){
    value = v;
}
template <class T>
ListNode<T>& ListNode<T>::operator=(const ListNode<T>& rhs){
    next = rhs.next;
    value = rhs.value;
}