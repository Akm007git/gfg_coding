//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool solve(int start,vector<int>adj[],vector<bool>&visited)
    {
        int parent  = -1; // for firat case
        queue<pair<int,int>>q;
        q.push({start,parent});
        visited[start] = true;
        
        while(!q.empty())
        {
            int node = q.front().first;
             parent = q.front().second;
            q.pop();
            
            // adj nodes
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    q.push({it,node});
                    visited[it] = true;
                }
                else
                {
                    if(it != parent && visited[it])
                    {
                        return true;
                    }
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
        
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(solve(i,adj,visited))
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