#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    vector<pair<TreeNode*, int>> children;  // Pair of child node and edge weight

    TreeNode(int value) : data(value) {}

    void addChild(TreeNode* child, int weight) {
        children.push_back(make_pair(child, weight));
    }
};

class Graph {
public:
    vector<TreeNode*> nodes;

    void addNode(TreeNode* node) {
        nodes.push_back(node);
    }

    void printGraph() {
        for (TreeNode* node : nodes) {
            cout << "Node " << node->data << " -> ";
            for (auto child : node->children) {
                cout << "(" << child.first->data << ", " << child.second << ") ";
            }
            cout << endl;
        }
    }

    int findTreeHeight(TreeNode* root) {
        if (!root)
            return 0;

        int maxHeight = 0;
        for (auto child : root->children) {
            int childHeight = 1 + findTreeHeight(child.first);
            maxHeight = max(maxHeight, childHeight);
        }
        return maxHeight;
    }

    void dfs(TreeNode* node) {
        cout << node->data << " ";

        for (auto child : node->children) {
            dfs(child.first);
        }
    }
};

int main() {
    // Creating nodes
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);

    // Creating a graph
    Graph graph;
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);
    graph.addNode(node4);

    // Adding weighted edges
    node1->addChild(node2, 2);
    node1->addChild(node3, 3);
    node2->addChild(node4, 1);

    // Print the graph
    cout << "Graph representation (weighted adjacency list):" << endl;
    graph.printGraph();

    // Find the height of the tree
    int treeHeight = graph.findTreeHeight(node1);
    cout << "\nTree height: " << treeHeight << endl;

    // Perform DFS traversal
    cout << "\nDFS traversal starting from node 1: ";
    graph.dfs(node1);

 delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
