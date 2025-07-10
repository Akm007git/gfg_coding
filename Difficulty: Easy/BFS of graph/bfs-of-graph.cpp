class Solution {
    private:
    void bfs(int start,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans)
    {
        //start with firat node
        // initialize a queue
        queue<int>q;
        q.push(start);
        visited[start] = true;
        
        // operation
        while(!q.empty())
        {
            int frontNode = q.front();
            ans.push_back(frontNode); // store while popping from the queue
            q.pop();
            
            // now traverse the adjacent node
            for(auto it:adj[frontNode])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int v  = adj.size();
        
        vector<bool>visited(v,false);
        vector<int>ans;
        
        for(int i = 0;i<v;i++)
        {
            if(!visited[i])
            {
                bfs(i,adj,visited,ans);
            }
        }
        
        return ans;
        
    }
};