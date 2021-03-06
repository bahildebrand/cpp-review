#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> data = {0, 1, 2, 3};
    Graph<int> g(data);
    g.addEdge(0,1,3);
    g.addEdge(0,2,5);
    g.addEdge(1,2,1);
    g.addEdge(2,3,4);
    g.addEdge(2,3,2);
    g.addEdge(3,3,1);
    g.addEdge(2,1,1);
    g.addEdge(3,1,4);
    g.addEdge(2,1,5);
    
    g.printGraph();
    vector<int> result = g.shortestPath(0, 3);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it){
        cout << *it << endl;
    }
}