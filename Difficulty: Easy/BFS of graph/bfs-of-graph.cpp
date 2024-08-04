//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] {0}; // number of nodes
        visited[0] = true;
        
        queue<int>q;
        q.push(0);
        
        vector<int>bfs;// store the value
        
        while(!q.empty())
        {
            int node  = q.front();
            q.pop();
            
            // ad into ans
            bfs.push_back(node);
            
            // traverse all adj
            for(auto it:adj[node]) // adj[node] represents a vector and it all the eemnt
            {
                if(visited[it] == 0)
                {
                    // two things
                    // mark viited
                    // push queueue
                   
                    q.push(it);
                     visited[it] = 1;
                }
            }
        }
        return bfs;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends