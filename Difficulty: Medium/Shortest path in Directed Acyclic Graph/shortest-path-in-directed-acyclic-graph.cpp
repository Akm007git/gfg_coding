//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    // DFS function to perform topological sorting
    void dfs(int start, vector<pair<int,int>> adj[], vector<bool>& visited, stack<int>& st) {
        visited[start] = true;
        
        for (auto it : adj[start]) {
            int u = it.first;
            if (!visited[u]) {
                dfs(u, adj, visited, st);
            }
        }
        
        st.push(start);  // Store the node in stack upon returning
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        if (N == 0 || M == 0) {
            return {};  // Handle empty graph case
        }
        
        // Create adjacency list
        vector<pair<int,int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // Perform topological sorting using DFS
        vector<bool> visited(N, false);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        
        // Initialize distance vector
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;  // Assuming the source node is 0
        
        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (dist[node] != INT_MAX) {  // Process only if node has been reached
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        // Replace INT_MAX with -1 to indicate unreachable nodes
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends