#include <iostream> 
#include <vector>

using namespace std;
int main () 

{
  cout<<"hi";
}

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}

    void addChild(TreeNode* child) {
        children.push_back(child);
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
            for (TreeNode* child : node->children) {
                cout << child->data << " ";
            }
            cout << endl;
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

    // Adding edges (connecting nodes in the tree structure)
    node1->addChild(node2);
    node1->addChild(node3);
    node2->addChild(node4);

    // Print the graph
    cout << "Graph representation (adjacency list):" << endl;
    graph.printGraph();

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

  
