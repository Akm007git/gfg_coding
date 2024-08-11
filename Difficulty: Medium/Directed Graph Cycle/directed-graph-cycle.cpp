//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool solve(int start,vector<int>adj[],vector<bool>&visited,vector<bool>&recurstack)
    {
        // initially
        visited[start] = true;
        recurstack[start] = true;
        
        // adjcent
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                if(solve(it,adj,visited,recurstack))
                {
                    return true;
                }
            }
            else // it is visited then
            {
                
                if(recurstack[it]) // if yes means in same oath is is peeviosly visited
                {
                    return true;
                }
            }
        }
        
        // while returning from thr sme path make recurdatck false
        recurstack[start] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>recurstack(V,false);
         vector<bool>visited(V,false);
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                if(solve(i,adj,visited,recurstack))
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