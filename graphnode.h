#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
using namespace std;

template <typename T> class GraphNode{
    T value;
    bool visited;
    int index;
    public:
        GraphNode();
        GraphNode(const GraphNode<T>&);
        GraphNode(T, int, bool);

        T getValue() const;
        bool isVisited() const;
        int getIndex() const;

        void setValue(const T);
        void markVisited();
        void markUnvisited();
        void setIndex(const int);

        void print() const;

        GraphNode<T>& operator=(const GraphNode<T>&);

        template <class Y>
        friend ostream& operator<<(ostream&, const GraphNode<T>&);
};
#include "graphnode.cpp"
#endif