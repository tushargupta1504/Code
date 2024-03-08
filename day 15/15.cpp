#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Edge {
public:
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
public:
    int vertices;
    vector<vector<Edge>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int from, int to, int weight) {
        adjList[from].emplace_back(to, weight);
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

    vector<int> dijkstra(int source) {
        vector<int> dist(vertices, numeric_limits<int>::max());
        dist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    // Creating a weighted directed graph
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 3, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 1, 3);
    graph.addEdge(2, 3, 9);
    graph.addEdge(2, 4, 2);
    graph.addEdge(3, 4, 4);
    graph.addEdge(4, 3, 6);

    // Print the graph
    cout << "Graph representation (weighted directed adjacency list):" << endl;
    graph.printGraph();

    // Find the shortest paths from source node 0 using Dijkstra's algorithm
    int sourceNode = 0;
    vector<int> shortestPaths = graph.dijkstra(sourceNode);

    cout << "\nShortest paths from source node " << sourceNode << ":\n";
    for (int i = 0; i < graph.vertices; ++i) {
        cout << "To vertex " << i << ": " << shortestPaths[i] << endl;
    }

    return 0;
}
