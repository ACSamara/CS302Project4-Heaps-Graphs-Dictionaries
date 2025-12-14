#include "arraylist.h"

template <class T>
ArrayList<T>::ArrayList(){
    max = 5;
    length = 0;
    data = new T[max];
}
template <class T>
bool ArrayList<T>::insert(int index, const T& obj){
    if(length<index||index<0){
        return false;
    }
    if(length >= max){
        max+=2;
        T* temp = new T[max];
        for(int i=0; i<length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    // Move everything over; doesn't run if inserting at end
    for(int i=length; i>index; i--){
        data[i] = data[i-1];
    }
    data[index] = obj;
    length ++;
    return true;
}
template <class T>
bool ArrayList<T>::insert(const T& obj){
    if(length >= max){
        max+=2;
        T* temp = new T[max];
        for(int i=0; i<length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
    data[length] = obj;
    length ++;
    return true;
}
template <class T>
bool ArrayList<T>::remove(int index){
    if(index<0||index>=length){
        return false;
    }
    for(int i=index; i<length-1; i++){
        data[i] = data[i+1];
    }
    length --;
    return true;
}
template <class T>
T ArrayList<T>::get(int i) const{
    return data[i];
}
template <class T>
T* ArrayList<T>::getAll() const{
    return data;
}
template <class T>
int ArrayList<T>::size() const{
    return length;
}
template <class T>
bool ArrayList<T>::isEmpty() const{
    if (length == 0){
        return true;
    }
    return false;
}
template <class T>
void ArrayList<T>::print() const{
    for (int i= 0; i<length; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
template <class T>
void ArrayList<T>::clear() const{
    length = 0;
    max = 5;
    delete[] data;
    data = new T[max];
}
template <class T>
T& ArrayList<T>::operator[](int index){
    return data[index];
}