#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;  // Adjacency list with pairs representing (neighbor, weight)

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int from, int to, int weight) {
        adjList[from].emplace_back(to, weight);
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << " -> ";
            for (auto neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    bool hasCycle() {
        unordered_set<int> visited;
        unordered_set<int> recursionStack;

        for (int i = 0; i < vertices; ++i) {
            if (hasCycleDFS(i, visited, recursionStack)) {
                return true;
            }
        }

        return false;
    }

    bool hasCycleDFS(int node, unordered_set<int>& visited, unordered_set<int>& recursionStack) {
        if (recursionStack.count(node)) {
            // Node is part of the current recursion stack, indicating a cycle
            return true;
        }

        if (visited.count(node)) {
            // Node has already been visited, no cycle through this node
            return false;
        }

        visited.insert(node);
        recursionStack.insert(node);

        for (auto neighbor : adjList[node]) {
            if (hasCycleDFS(neighbor.first, visited, recursionStack)) {
                return true;
            }
        }

        recursionStack.erase(node);

        return false;
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

            for (auto neighbor : adjList[currentVertex]) {
                int adjacentVertex = neighbor.first;
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
    // Creating a directed weighted graph
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 2, 2);

    // Print the graph
    cout << "Graph representation (weighted directed adjacency list):" << endl;
    graph.printGraph();

    // Check if the graph has a cycle
    if (graph.hasCycle()) {
        cout << "\nThe graph has a cycle." << endl;
    } else {
        cout << "\nThe graph does not have a cycle." << endl;
    }

    // Perform BFS traversal
    graph.bfs(0);

    return 0;
}
