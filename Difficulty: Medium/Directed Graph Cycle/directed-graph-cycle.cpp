//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    bool dfs(int start,vector<int>adj[],int visited[],int recurStack[])
    {
        // initally
        visited[start] = 1;
        recurStack[start] = 1;
        
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                if(dfs(it,adj,visited,recurStack))
                {
                    return true;
                }
            }
            
            // visited is true meas visited but has to be in the dame parh thats why i has to be in the ssme path
            else if(recurStack[it])
            {
                return true;
            }
        }
        
        // when path end then just check that its recurstack visited or not
        recurStack[start] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int recurStack[V] = {0};
        
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,recurStack))
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends