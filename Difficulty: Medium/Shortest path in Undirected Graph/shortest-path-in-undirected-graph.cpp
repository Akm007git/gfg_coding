//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // create adjacency list
        vector<int>adj[N];
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            
            // push
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // craete dist array
        vector<int>dist(N,INT_MAX);
        dist[src] = 0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty())
        {
            int node =  q.front();
            q.pop();
            
            //traverse neighbours
            for(auto it:adj[node])
            {
                if(dist[node] + 1 < dist[it])
                {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
         // otherse make -1
            for(int i = 0;i<N;i++)
            {
                if(dist[i] == INT_MAX)
                {
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends