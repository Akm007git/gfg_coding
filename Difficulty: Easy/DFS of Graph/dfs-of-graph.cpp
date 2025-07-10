class Solution {
    private:
    void dfs(int start,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans)
    {
        ans.push_back(start); //store
        visited[start] = true; //vistd the fisrt time
        
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                dfs(it,adj,visited,ans);
            }
        }
    }
    
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v,false);
        vector<int>ans;
        
        for(int i = 0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,ans);
            }
        }
        return ans;
        
    }
};