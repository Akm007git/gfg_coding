//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  
    int solve(int price[],vector<int>&v,int n,int w,vector<vector<int>>&dp)
    {
        // base
        if(n == 0 || w == 0)
        {
            return 0;
        }
        if(dp[n][w] != -1) return dp[n][w];
        
        if(v[n-1] <= w)
        {
            return dp[n][w] =  max(price[n-1] + solve(price,v,n,w - v[n-1],dp),
                    solve(price,v,n-1,w,dp));
        }
        else
        {
            return dp[n][w] =  solve(price,v,n-1,w,dp);
        }
    }
    
    
  public:
    int cutRod(int price[], int n) {
        //code here
        
        vector<int>v(n);
        for(int i = 0;i<n;i++)
        {
            v[i] = i+1;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(price,v,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends