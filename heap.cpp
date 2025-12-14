#include "heap.h"

template <class T>
Heap<T>::Heap(){
    size = 0;
    maxSize = 50;
    data = new T[maxSize];
    depth = 0;
}
template <class T>
void Heap<T>::maxHeapify(int root){
    int n = 1;
    for(int i=0; i<depth-1; i++){
        n*=2;
    }
    if(root>=n-1){
        return;
    }

    int largeChild = getLeft(root);
    if(size>getRight(root)){
        if(data[getRight(root)]>data[largeChild]){
            largeChild = getRight(root);
        }
    }
    if(data[root]<data[largeChild]){
        // Swap
        T temp = data[largeChild];
        data[largeChild] = data[root];
        data[root] = temp;      

        maxHeapify(largeChild);
    }
}
template <class T>
int Heap<T>::getParent(int child){
    return (child-1)/2;
}
template <class T>
int Heap<T>::getLeft(int parent){
    return 2*parent+1;
}
template <class T>
int Heap<T>::getRight(int parent){
    return 2*parent+2;
}
template <class T>
bool Heap<T>::insert(T item){
    if(size>=maxSize){
        maxSize+=2;
        data = resizeArray(data, maxSize, size);
    }

    data[size] = item;
    size++;
    for(int i=size;i>=0;i--){
        maxHeapify(i);
    }
    return true;
}
template <class T>
T Heap<T>::extractMax(){
    T max = data[0];
    data[0] = data[size-1];
    size --;
    maxHeapify(0);

    return max;
}
template <class T>
T Heap<T>::peek(){
    return data[0];
}
template <class T>
void Heap<T>::buildMaxHeap(int n, T* arr){
    size = n;
    for(int i=0; i<size; i++){
        data[i] = arr[i];
    }
    getDepth();
    for(int i=size;i>=0;i--){
        maxHeapify(i);
    }
}
template <class T>
bool Heap<T>::isEmpty(){
    if(size==0){
        return true;
    }
    return false;
}
template <class T>
void Heap<T>::clear(){
    size = 0;
    maxSize = 5;
    delete[] data;
    data = new T[maxSize];
}
template <class T>
int Heap<T>::getDepth() {
    int a = 1;
    depth = 0;
    while(a<=size+1){
        a*=2;
        depth ++;
    }
    return depth;
}
template <typename T>
void Heap<T>::print(){
    for(int i=0; i<size; i++){
        cout<<data[i];
    }
}