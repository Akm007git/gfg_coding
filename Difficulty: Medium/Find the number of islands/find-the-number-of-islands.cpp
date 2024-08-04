//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row,int col,vector<vector<char>> grid,vector<vector<bool>>&visited)
    {
        
        int n = grid.size();
        int m = grid[0].size();
        // initially ,ark them true
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col] = true;
        
        // traverse the neighboures
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // atch the neighbours
            
            for(int i = -1;i <=1;i++)
            {
                for(int j = -1;j<=1;j++)
                {
                    int nrow = row + i;
                    int ncol = col + j;
                    
                    // main logic for fbs
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == '1' && !visited[nrow][ncol] )
                    {
                        q.push({nrow,ncol});
                        visited[nrow][ncol] = true;
                     
                    }
                }
            }
            
            
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        int count = 0;
        //traverse
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                 
                    bfs(i,j,grid,visited);
                        count++;
                  
                }
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends