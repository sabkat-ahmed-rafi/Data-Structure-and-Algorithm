#include <iostream>
#include <vector>
using namespace std;


class Graph {
private:
    int V;
    vector<vector<int>> adjList;
public:
    Graph(int value) {
        int v = value;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph() {
        for(int i = 0; i < V; i++) {
            cout << i << ": ";
            for(int j :  adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Graph g(4); // Graph with 4 vertices (0, 1, 2, 3)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.printGraph();

    return 0;
}