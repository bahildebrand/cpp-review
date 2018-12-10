#include "Graph.hpp"

using namespace std;

int main(void) {
    vector<int> data = {0, 1, 2, 3};
    Graph<int> g(data);
    g.addEdge(0,1,3);
    g.addEdge(0,2,5);
    g.addEdge(1,2,1);
    g.addEdge(2,3,4);
    g.addEdge(2,4,2);
    g.addEdge(3,4,1);
    g.printGraph();
}