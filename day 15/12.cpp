#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Edge {
public:
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int from, int to, int weight, bool isDirected = true) {
        adjList[from].emplace_back(from, to, weight);

        if (!isDirected) {
            adjList[to].emplace_back(to, from, weight);
        }
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << " -> ";
            for (auto& edge : adjList[i]) {
                cout << "(" << edge.to << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout << "BFS traversal starting from vertex " << startVertex << ": ";

        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            for (auto& edge : adjList[currentVertex]) {
                int adjacentVertex = edge.to;
                if (!visited[adjacentVertex]) {
                    q.push(adjacentVertex);
                    visited[adjacentVertex] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    // Creating an undirected weighted graph
    Graph graph(6);
    graph.addEdge(0, 1, 2, false);
    graph.addEdge(0, 2, 1, false);
    graph.addEdge(1, 3, 4, false);
    graph.addEdge(2, 4, 3, false);
    graph.addEdge(3, 2, 2, false);
    graph.addEdge(4, 5, 1, false);

    // Print the graph
    cout << "Graph representation (weighted undirected adjacency list):" << endl;
    graph.printGraph();

    // Perform BFS traversal
    graph.bfs(0);

    return 0;
}
