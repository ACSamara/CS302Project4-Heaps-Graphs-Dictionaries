#include "arrayqueue.h"

template <class T>
ArrayQueue<T>::ArrayQueue(){
    max = 5;
    length = 0;
    data = new T[max];
}
template <class T>
bool ArrayQueue<T>::enqueue(const T& value){
    if(length >= max){
        max+=2;
        T* temp = new T[max];
        for(int i=0; i<length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    data[length] = value;
    length ++;
    return true;
}
template <class T>
T ArrayQueue<T>::dequeue(){
    T output = data[0];
    length --;
    for(int i=0; i<length; i++){
        data[i] = data[i+1];
    }
    return output;
}
template <class T>
T ArrayQueue<T>::peek() const{
    return data[0];
}
template <class T>
bool ArrayQueue<T>::isEmpty() const{
    if(length == 0){
        return true;
    }
    return false;
}
template <class T>
void ArrayQueue<T>::print() const{
    cout<<"BACK | ";
    for (int i=length; i>0; i--){
        cout<<data[i-1]<<" ";
    }
    cout<<"| FRONT"<<endl;
}