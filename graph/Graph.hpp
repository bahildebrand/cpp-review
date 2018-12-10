#ifndef GRAPH__
#define GRAPH__

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

template <class T> class Graph {
    protected:
        class Node {
            public:
                vector<pair<int,int>> edges;
                T data;
        };

    private:
        vector<Node> *nodes;

    public:
        Graph(vector<T> d);
        ~Graph() { delete this->nodes; }
        bool addEdge(int start, int end, int weight);
        bool addNode(T data);
        void printGraph();
        vector<int> shortestPath(int start, int end);
};

template <class T> bool Graph<T>::addEdge(int start, int end, int weight) {
    int size = this->nodes->size();

    if(start < size && end < size ){
        this->nodes->at(start).edges.push_back(pair<int,int>(end,weight));
        return true;
    } else {
        return false;
    }
}

template <class T> Graph<T>::Graph(vector<T> d) {
    this->nodes = new vector<Node>(d.size());
    
    int i;
    for(i = 0; i < d.size(); i++) {
        this->nodes->at(i).data = d[i];
    }
}

template <class T> void Graph<T>::printGraph() {
    int i;
    int j;

    for(i = 0; i < this->nodes->size(); i++) {
        cout << i << ": ";
        for(j = 0; j < this->nodes->at(i).edges.size(); j++) {
            cout << "E=" << this->nodes->at(i).edges[j].first << " ";  
            cout << "W=" << this->nodes->at(i).edges[j].second << " ";
            cout << "D=" << this->nodes->at(i).data << ", ";
        }
        cout << endl;
    }
}

template <class T> vector<int> Graph<T>::shortestPath(int start, int end) { 
    vector<int> result;
    vector<bool> visited(this->nodes->size(), false);

    
}

#endif // GRAPH__
