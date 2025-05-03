#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


 void dfs(int v,  vector<bool>& visited, vector<vector<int>>& adj) {
    visited[v] = true;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}
bool is_cycle_graph(int N, int M, vector<pair<int, int>>& edges) {
    if (M != N) {
        return false;
    }
    
    vector<vector<int>> adj(N + 1);
    vector<int> degree(N + 1, 0);
    
    for (const auto& edge : edges) {
        int a = edge.first, b = edge.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= N; ++i) {
        if (degree[i] != 2) {
            return false;
        }
    }
  
    vector<bool> visited(N + 1, false);

    dfs(1, visited, adj);
 
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    if (is_cycle_graph(N, M, edges)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
