#include "linkedlist.h"

template <class T>
LinkedList<T>::LinkedList(){
    first = nullptr;
    length = 0;
}
/*
Overload to insert obh=ject at a specified index.
*/
template <class T>
bool LinkedList<T>::insert(int index, const T& obj){
    ListNode<T>* previous = first;
    ListNode<T>* current = nullptr;
    if(length<index||index<0){
        return false;
    }
    if(index == 0){
        if(length != 0){
            current = first;
        }
        first = new ListNode<T>(current, obj);
    }
    else{ 
        for(int i=0; i<index-1;i++){
            previous = previous->getNext();
        }       
        current = new ListNode(previous->getNext(), obj);
        previous->setNext(current);
    }
    previous = current = nullptr;
    delete previous, current;
    length ++;
    return true;
}
/*
Overload to insert object at end of list.
*/
template <class T>
bool LinkedList<T>::insert(const T& obj){
    ListNode<T>* current = nullptr, *previous = first;
    if(length==0){
        first = new ListNode<T>(current, obj);
    }
    else{
        for(int i=0; i<length-1;i++){
            previous = previous->getNext();
        }       
        current = new ListNode(previous->getNext(), obj);
        previous->setNext(current);
    }
    previous = current = nullptr;
    delete previous, current;
    length ++;
    return true;
}
template <class T>
bool LinkedList<T>::remove(int index){
    ListNode<T>* previous = first, *current = nullptr;
    if(index<0||index>=length){
        return false;
    }
    if(index == 0){
        first = first->getNext();
        previous = nullptr;
        delete previous;
        length --;
        return true;
    }
    for(int i=0; i<index-1; i++){
        previous = previous->getNext();
    }
    current = previous->getNext();
    if(current->getNext()!= nullptr){
        previous->setNext(current->getNext());
    }
    else{
        previous->setNext(nullptr);
    }
    current = nullptr;
    delete current;
    length --;
    return true;
}
template <class T>
T LinkedList<T>::get(int index) const{
    ListNode<T>* temp = first;
    for(int i=0; i<index; i++){
        temp = temp->getNext();
    }
    return temp->getValue();
}
template <class T>
int LinkedList<T>::size() const{
    return length;
}
template <class T>
bool LinkedList<T>::isEmpty() const{
    if(length <= 0){
        return true;
    }
    return false;
}
template <class T>
void LinkedList<T>::print() const{
    ListNode<T>* current = first;
    if(!isEmpty()){
        while(current!=nullptr){
            cout<<current->getValue()<<" ";
            current = current->getNext();
        }
    }
    cout<<endl;
}
template <class T>
T LinkedList<T>::operator[](int index) const{
    ListNode<T>* temp = first;
    for(int i=0; i<index; i++){
        temp = temp->getNext();
    }
    return temp->getValue();
}