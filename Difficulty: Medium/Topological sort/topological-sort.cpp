//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void solve(int start,stack<int>&st,vector<int>adj[],vector<bool>&visited)
    {
        // base type
        visited[start] = true;
        
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                solve(it,st,adj,visited);
            }
        }
        // while returning
        // push in stack
        
        st.push(start);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<bool>visited(V,false);
	    
	   for(int i = 0;i<V;i++)
	   {
	       if(!visited[i])
	       {
	           solve(i,st,adj,visited);
	       }
	   }
	   // got everitjing in stack
	   vector<int>v;
	   while(!st.empty())
	   {
	       v.push_back(st.top());
	       st.pop();
	   }
	   
	   return v;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends