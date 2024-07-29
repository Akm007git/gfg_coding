//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int length[],int price[],int N,int n,vector<vector<int>>&dp)
    {
        if(N == 0 || n == 0)
        {
            return 0;
        }
        // memo
        if(dp[N][n] != -1)
        {
            return dp[N][n];
        }
        
        // choice diagram
        if(length[n-1] <= N)
        {
            return dp[N][n] =  max((price[n-1] + solve(length,price,N-length[n-1],n,dp)),solve(length,price,N,n-1,dp)); // take ,not take
        }
        else
        {
            return dp[N][n] =  solve(length,price,N,n-1,dp); // not take
        }
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        int length[n];
        for(int i=0;i<n;i++)
        {
            length[i] = i+1;
        }
        // length array ready
        // indexing from last(n); thats why n, n
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return solve(length,price,n,n,dp);
        
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