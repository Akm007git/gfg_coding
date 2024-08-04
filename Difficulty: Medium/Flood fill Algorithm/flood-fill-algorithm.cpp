//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>>&adj,int initColor,int newColor)
    {
        // initially mark tem new color
        //size
        int n = adj.size();
        int m = adj[0].size();
        
        queue<pair<int,int>>q;
        q.push({row,col});
        adj[row][col] = newColor;
        
        // traverse the queue
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // traverse the 4 durectiom
            // i heve to check those 4 ways
            int delRow[] = {0,-1,0,1};
            int delCol[] = {-1,0,1,0};
            
            for(int i = 0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <m &&
                   adj[nrow][ncol] == initColor && adj[nrow][ncol] != newColor )
                   {
                      adj[nrow][ncol] = newColor;
                      q.push({nrow,ncol});
                    }
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        vector<vector<int>>adj = image;
        int initColor = image[sr][sc];
        
        // traversal
        bfs(sr,sc,adj,initColor,newColor);
        return adj;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends