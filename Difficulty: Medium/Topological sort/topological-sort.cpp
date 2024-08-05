//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V);
	    
	    for(int i = 0;i< V;i++)
	    {
	        // 1.  store the indegreee
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    // mapping done
	    
	    queue<int>q;
	    
	    // 2. push into queue as 0 indegree as initial point
	    // also initit a map to store  the data
	    
	    for(int i = 0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    vector<int>v;
	    
	    // travrese the queueue
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        // store the node
	        v.push_back(node);
	        
	        // traverse the neighbour
	        
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
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