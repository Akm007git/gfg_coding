//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(int start,vector<int>adj[],vector<bool>&visited)
    {
        // initially push in queueue
        queue<pair<int,int>>q; // node and parent inpair
        q.push({start,-1});
        visited[start] = true;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it] = true;
                    q.push({it,node});
                }
                else if(it != parent && visited[it])
                {
                    return true;
                }

            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        for(int  i  = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if (bfs(i,adj,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends