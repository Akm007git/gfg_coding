//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        // make a queue
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2 && !visited[i][j])
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                    
                }
            }
        }
        
        // forth side
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        
        int time  = 0;
        int total_time = 0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time  = q.front().second;
            q.pop();
            
            // save the time 
            total_time  = time;
            
            for(int i = 0;i<4;i++)
            {
                int nrow  = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                 && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                 {
                     q.push({{nrow,ncol},time+1});
                     visited[nrow][ncol] = 2;
                 }
            }
        }
       // cout<<
        
        // check any left
       for(int i = 0;i<n;i++)
       {
           for(int j = 0;j<m;j++)
           {
               if(grid[i][j] == 1 && visited[i][j] != 2)
               {
                   return -1;
               }
           }
       }
        return total_time;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends