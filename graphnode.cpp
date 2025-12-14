#include "graphnode.h"

template <class T>
GraphNode<T>::GraphNode(){
    visited = false;
    index = 0;
}
template <class T>
GraphNode<T>::GraphNode(const GraphNode<T>& rhs){
    value = rhs.value;
    visited = rhs.visited;
    index = rhs.index;
}
template <class T>
GraphNode<T>::GraphNode(T val, int i, bool vis){
    value = val;
    visited = vis;
    index = i;
}
template <class T>
T GraphNode<T>::getValue() const{
    return value;
}
template <class T>
bool GraphNode<T>::isVisited() const{
    return visited;
}
template <class T>
int GraphNode<T>::getIndex() const{
    return index;
}
template <class T>
void GraphNode<T>::setValue(const T v){
    value = v;
}
template <class T>
void GraphNode<T>::markVisited(){
    visited = true;
}
template <class T>
void GraphNode<T>::markUnvisited(){
    visited = false;
}
template <class T>
void GraphNode<T>::setIndex(const int i){
    index = i;
}
template <class T>
void GraphNode<T>::print() const{
    cout<<value;
}
template <class T>
ostream& operator<<(ostream& out, const GraphNode<T>& obj){
    obj.print();
    return out;
}
template <class T>
GraphNode<T>& GraphNode<T>::operator=(const GraphNode<T>& rhs){
    value = rhs.value;
    visited = rhs.visited;
    index = rhs.index;

    return *this;
}