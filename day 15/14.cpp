#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

    vector<int> dijkstra(int startVertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(vertices, INT_MAX);

        pq.push({0, startVertex});
        distance[startVertex] = 0;

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();

            if (currentDistance > distance[currentVertex]) {
                continue;
            }

            for (auto& edge : adjList[currentVertex]) {
                int adjacentVertex = edge.to;
                int newDistance = currentDistance + edge.weight;

                if (newDistance < distance[adjacentVertex]) {
                    distance[adjacentVertex] = newDistance;
                    pq.push({newDistance, adjacentVertex});
                }
            }
        }

        return distance;
    }
};

int main() {
    // Creating a weighted directed graph
    Graph graph(5);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 3);

    // Print the graph
    cout << "Graph representation (weighted directed adjacency list):" << endl;
    graph.printGraph();

    // Find the shortest distances using Dijkstra's algorithm
    int startVertex = 0;
    vector<int> shortestDistances = graph.dijkstra(startVertex);

    cout << "\nShortest distances from vertex " << startVertex << " using Dijkstra's algorithm:\n";
    for (int i = 0; i < graph.vertices; ++i) {
        cout << "To vertex " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
