#include <bits/stdc++.h>
using namespace std;

// Define a large constant for calculations
const int MODULO = 1e9 + 7;

// Arrays to store information about nodes and edges
int parent[200010];
int ancestor[200010][22], maxEdge[200010][22];
int depth[200010];
vector<pair<int, int>> graph[200010], tree[200010];
vector<tuple<int, int, int>> edges, originalEdges;

// Function to find the root of a node
int findRoot(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

// Function to unite two nodes
void uniteNodes(int nodeA, int nodeB) {
    parent[findRoot(nodeA)] = findRoot(nodeB);
}

// Depth-first search to set up ancestor and maxEdge arrays
void depthFirstSearch(int currentNode, int parentNode) {
    depth[currentNode] = depth[parentNode] + 1;
    ancestor[currentNode][0] = parentNode;
    
    for (int i = 1; i < 20; i++) {
        ancestor[currentNode][i] = ancestor[ancestor[currentNode][i - 1]][i - 1];
        maxEdge[currentNode][i] = max(maxEdge[currentNode][i - 1], maxEdge[ancestor[currentNode][i - 1]][i - 1]);
    }
    
    for (auto [nextNode, weight] : tree[currentNode]) {
        if (nextNode == parentNode) continue;
        maxEdge[nextNode][0] = weight;
        depthFirstSearch(nextNode, currentNode);
    }
}

// Function to find the largest edge in the path between two nodes
int largestEdgeInPath(int nodeA, int nodeB) {
    if (depth[nodeA] < depth[nodeB]) swap(nodeA, nodeB);
    int maxEdgeWeight = -1;
    
    for (int i = 19; i >= 0; i--) {
        if (depth[ancestor[nodeA][i]] >= depth[nodeB]) {
            maxEdgeWeight = max(maxEdgeWeight, maxEdge[nodeA][i]);
            nodeA = ancestor[nodeA][i];
        }
    }
    
    for (int i = 19; i >= 0; i--) {
        if (ancestor[nodeA][i] != ancestor[nodeB][i]) {
            maxEdgeWeight = max({maxEdgeWeight, maxEdge[nodeA][i], maxEdge[nodeB][i]});
            nodeA = ancestor[nodeA][i];
            nodeB = ancestor[nodeB][i];
        }
    }
    
    if (nodeA == nodeB) return maxEdgeWeight;
    return max({maxEdgeWeight, maxEdge[nodeA][0], maxEdge[nodeB][0]});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    
    // Initialize each node as its own parent
    for (int i = 1; i <= numNodes; i++) {
        parent[i] = i;
    }
    
    // Read edges and store them
    for (int i = 0; i < numEdges; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].emplace_back(nodeB, weight);
        graph[nodeB].emplace_back(nodeA, weight);
        edges.emplace_back(weight, nodeA, nodeB);
        originalEdges.emplace_back(nodeA, nodeB, weight);
    }
    
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    int totalWeight = 0;
    
    // Build the minimum spanning tree
    for (auto [weight, nodeA, nodeB] : edges) {
        if (findRoot(nodeA) != findRoot(nodeB)) {
            uniteNodes(nodeA, nodeB);
            totalWeight += weight;
            tree[nodeA].emplace_back(nodeB, weight);
            tree[nodeB].emplace_back(nodeA, weight);
        }
    }
    
    // Prepare data structures for LCA queries
    depthFirstSearch(1, 0);
    
    // Calculate and print the result for each original edge
    for (auto [nodeA, nodeB, weight] : originalEdges) {
        cout << totalWeight + weight - largestEdgeInPath(nodeA, nodeB) << '\n';
    }
    
    return 0;
}
