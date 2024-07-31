//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    // private:
    // int solve(string &s1,int m,string &s2,int n,int count)
    // {
    //     // base case
    //     if(m==0 || n == 0)
    //     {
    //         return count;
    //     }
    //     // choice diagram
    //     if(s1[m-1] == s2[n-1])
    //     {
    //         return  solve(s1,m-1,s2,n-1,count+1);
    //     }
    //     else
    //     {
    //       return max(count,max(
    //           solve(s1,m-1,s2,n,0), solve(s1,m,s2,n-1,0)));
    //     }
    // }
    
    // memo
    //int maxi = 0;
    int solve(string &s1,int m,string &s2,int n,vector<vector<int>>&dp)
    {
        // if(n == 0 ||m == 0)
        // {
        //     return count;
        // }
    for(int i = 0;i<m+1;i++)
    {
        for (int j = 0;j<n+1;j++)
        {
            if(i == 0 || j == 0)
            {
                 dp[i][j] = 0;
            }
        }
    }
        
        int ans  = 0;
     for(int i = 1;i<m+1;i++)
        {
            for(int j = 1 ;j<n+1;j++)
            {
                  if(s1[i-1] == s2[j-1] )
                  {
                      dp[i][j] = 1 +  dp[i-1][j-1];
                      ans = max(ans,dp[i][j]);
                  }
                  else
                  {
                      dp[i][j] = 0;
                  }
            }
        }
        return  ans;
    }
    
  public:
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int m = s1.size();
        int n = s2.size();
        // int count  = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return solve(s1,m,s2,n,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends