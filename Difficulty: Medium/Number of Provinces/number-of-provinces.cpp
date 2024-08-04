//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void solve(int start,vector<int>adj[],vector<bool>&visited)
    {
        // initially  mark visited
        visited[start] = true;
        
        //traverse
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                solve(it,adj,visited);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V]; // adjacency list
        
        for(int i = 0;i<V;i++)
        {
            for(int j = 0;j<V;j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // graph is ready
        int count = 0;
        vector<bool>visited(V,false);
        
        for(int i = 0;i<V;i++)
        {
            if(!visited[i])
            {
                solve(i,graph,visited);
                count++;
            }
        }
        return count ;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends