#include "graph.h"

template <class T>
Graph<T>::Graph(){
    size = 0;
    maxSize = 2;
    adjacencies = new int*[maxSize];
    for(int i=0; i<maxSize; i++){
        adjacencies[i] = new int[maxSize];
        for(int j=0; j<maxSize; j++){
            adjacencies[i][j] = 0;
        }
    }
    vertices = new GraphNode<T>[maxSize];
}

template <class T>
bool Graph<T>::addVertex(T val){
    if(findIndex(val)!=-1){
        return false;
    }

    // Resize
    if(size>=maxSize){
        maxSize+=2;
        vertices = resizeArray<GraphNode<T>>(vertices, maxSize, size);

        for(int i=0; i<size; i++){
            adjacencies[i] = resizeArray<int>(adjacencies[i], maxSize, size);
        }
        adjacencies = resizeArray<int*>(adjacencies, maxSize, size);
        for(int i=size; i<maxSize; i++){
            adjacencies[i] = new int[maxSize];
            for(int j=0; j<size; j++){
                adjacencies[i][j] = 0;
                adjacencies[j][i] = 0;
            }
        }
    }

    vertices[size] = GraphNode<T>(val, size, false);
    size++;
    for(int i=0; i<size; i++){
        adjacencies[size-1][i] = 0;
    }
    return true;
}

template <class T>
bool Graph<T>::addEdge(T u, T v, int weight){
    if(findIndex(u)==-1||findIndex(v)==-1){
        return false;
    }

    int i = findIndex(u);
    int j = findIndex(v);

    adjacencies[i][j] = weight;
    adjacencies[j][i] = weight;

    return true;
}

template <class T>
bool Graph<T>::removeEdge(T u, T v){
    if(findIndex(u)==-1||findIndex(v)==-1){
        return false;
    }

    int i = findIndex(u);
    int j = findIndex(v);

    if(!(adjacencies[i][j]&&adjacencies[j][i])){
        return false;
    }

    adjacencies[i][j] = 0;
    adjacencies[j][i] = 0;

    return true;
}

template <class T>
void Graph<T>::dfsPrint(){
    ArrayList<GraphNode<T>> arr;
    dfsHelper(vertices[0], arr);
    arr.print();
    cout<<endl;
    resetVisiting();
}

template <class T>
ArrayList<GraphNode<T>> Graph<T>::breadthFirstSearch(int index){
    ArrayQueue<GraphNode<T>> q;
    ArrayList<GraphNode<T>> output;

    vertices[index].markVisited();
    q.enqueue(vertices[index]);

    while(!q.isEmpty()){
        GraphNode<T> w(q.dequeue());
        for(int i=0; i<size; i++){
            if(adjacencies[w.getIndex()][i]&&!vertices[i].isVisited()){
                vertices[i].markVisited();
                q.enqueue(vertices[i]);
            }
        }
        output.insert(w);
    }
    resetVisiting();

    return output;
}

template <class T>
void Graph<T>::bfsPrint(){
    ArrayList<GraphNode<T>> arr = breadthFirstSearch(0);
    arr.print();
    cout<<endl;
}

template <class T>
void Graph<T>::printShortestPath(T u, T v){
    int uIndex = findIndex(u);
    int vIndex = findIndex(v);

    ArrayList<GraphNode<T>> forward, backward;
    dfsHelper(vertices[uIndex], forward);
    resetVisiting();
    dfsHelperReverse(vertices[uIndex], backward);
    resetVisiting();

    int count1 = 0, length1 = 0, previous = findIndex(forward[0].getValue());
    while(forward[count1].getValue()!=v&&count1<forward.size()){
        count1 ++;
        int next = findIndex(forward[count1].getValue());
        length1+=adjacencies[previous][next];
        previous = next;
    }
    int count2 = 0, length2 = 0;
    previous = findIndex(backward[0].getValue());
    while(backward[count2].getValue()!=v&&count2<backward.size()){
        count2 ++;
        int next = findIndex(backward[count2].getValue());
        length2+=adjacencies[previous][next];
        previous = next;
    }

    cout<<"===Shortest path from "<<u<<" to "<<v<<"==="<<endl;
    if(length1>length2){
        cout<<"Distance: "<<length2<<endl;
        for(int i=0; i<count2; i++){
            cout<<backward[i].getValue()<<" -> ";
        }
    }
    else{
        cout<<"Distance: "<<length1<<endl;
        for(int i=0; i<count1; i++){
            cout<<forward[i].getValue()<<" -> ";
        }
    }
    cout<<v<<endl;
}

template <class T>
void Graph<T>::resetVisiting(){
    for(int i=0; i<size; i++){
        vertices[i].markUnvisited();
    }
}

template <class T>
void Graph<T>::dfsHelper(GraphNode<T>& v, ArrayList<GraphNode<T>>& arr){
    v.markVisited();
    arr.insert(v);

    for(int i=0; i<size; i++){
        if(adjacencies[v.getIndex()][i]&&!vertices[i].isVisited()){
            dfsHelper(vertices[i], arr);
        }
    } 
}
template <class T>
void Graph<T>::dfsHelperReverse(GraphNode<T>& v, ArrayList<GraphNode<T>>& arr){
    v.markVisited();
    arr.insert(v);

    for(int i=size; i>0; i--){
        if(adjacencies[v.getIndex()][i-1]&&!vertices[i-1].isVisited()){
            dfsHelperReverse(vertices[i-1], arr);
        }
    }
}

template <class T>
int Graph<T>::findIndex(T val){
    for(int i=0; i<size; i++){
        if(vertices[i].getValue()==val){
            return i;
        }
    }
    return -1;
}