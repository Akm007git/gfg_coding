//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
    
    void solve(int row,int col,vector<vector<int>>&matrix,vector<vector<bool>>&visited,int n,
    string str,vector<string>&ans,int delRow [],int delCol [],string &direction)
    {
        // base
        if( row == n-1 && col == n-1)
        {
            ans.push_back(str);
            return;
        }
        
        // traverse the whole array
        
        for(int i = 0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
    
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol] &&
               matrix[nrow][ncol] == 1 )
               {
                   // two do
              
                   
                   // recursion
                   // visited
                   visited[nrow][ncol] = true;
                   
                   // recursion
                   solve(nrow,ncol,matrix,visited,n,str + direction[i],ans,delRow,delCol,direction);
                   
                   // while returning
                   visited[nrow][ncol] = false;
                   
                   
               }
        }
        
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &matrix) {
        // Your code goes here
            vector<string>ans;
             int n = matrix.size();
            if (n == 0) return ans; 
     
             string str = "";
      
        
          vector<vector<bool>>visited(n,vector<bool>(n,false));
                 
            int delRow [] = {-1,0,1,0};
            int delCol [] = {0,1,0,-1};
            string direction = "URDL";
    
        // syarting pouny
        if(matrix[0][0] == 1)
        {
            visited[0][0] = true;
            solve(0,0,matrix,visited,n,str,ans,delRow,delCol,direction);
           
        }
        
        
         return ans;
        
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends