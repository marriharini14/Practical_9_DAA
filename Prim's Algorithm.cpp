#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(int V, const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "\nEdge \tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << "\n";
}

void primMST(int V, const vector<vector<int>>& graph) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;    
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        
        int u = minKey(V, key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
        
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (" << V << " x " << V << "):\n";
    cout << "(Enter 0 if there is no direct edge between vertices)\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(V, graph);

    return 0;
}
