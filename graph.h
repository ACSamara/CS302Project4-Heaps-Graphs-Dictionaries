#ifndef GRAPH_H
#define GRAPH_H

#include "graphnode.h"
#include "arrayqueue.h"
#include "helpers.h"
#include "arraylist.h"

template <typename T> class Graph{
    int** adjacencies;
    GraphNode<T>* vertices;
    int size, maxSize;

    // Private functions
    void resetVisiting();
    void dfsHelper(GraphNode<T>&, ArrayList<GraphNode<T>>&);
    void dfsHelperReverse(GraphNode<T>&, ArrayList<GraphNode<T>>&);
    int findIndex(T);
    ArrayList<GraphNode<T>> breadthFirstSearch(int); 

    public:
        Graph();

        bool addVertex(T);
        bool addEdge(T u, T v, int weight);
        bool removeEdge(T u, T v);
        void dfsPrint();
        void bfsPrint();
        void printShortestPath(T u, T v);
};
/*
Helper function to increase the size of a dynamically allocated array.
Accessible from other classes as well.
*/
template <typename T>
T* resizeArray(T* old, int max, int size){
    T* temp = new T[max];
    for(int i=0;i<size; i++){
        temp[i] = old[i];
    }
    delete[] old;
    old = temp;
    return old;
}
#include "graph.cpp"
#endif