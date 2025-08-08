// User function Template for C++

class Solution {
    int rowArr[4] = {1,-1,0,0};
    int colArr[4] = {0, 0, -1, 1};
    
    private:
        void bfs(int startRow, int startCol, vector<vector<int>>& grid, string &s, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        visited[startRow][startCol] = true;
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Encode relative position
            s += to_string(row - startRow);
            s += to_string(col - startCol);
            
            for(int i = 0; i < 4; i++) {
                int nRow = row + rowArr[i];
                int nCol = col + colArr[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        // neeed ad visisted array
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        // ctateina a set for stoing the distince element
        set<string>st;
        
        
        // traverse the grid
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                string s;
                
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    bfs(i,j,grid,s,visited);
                    st.insert(s);
                }
            }
        }
        
        return st.size();
        
    }
};
