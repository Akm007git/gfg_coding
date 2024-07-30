//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

private:
int solve(vector<int>&coins,int n,int sum,vector<vector<int>>&dp)
{
    // base case
    if(sum == 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return INT_MAX-1;
    }
    
    // memo
    if(dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    
    // choice diagram
    if(coins[n-1] <= sum)
    {
        return dp[n][sum] =  min( (1 + solve(coins,n,sum-coins[n-1],dp)),
                            solve(coins,n-1,sum,dp) );
    }
    else
    {
       return dp[n][sum] = solve(coins,n-1,sum,dp);
    }
    
   // return dp[n][sum] = min(take,nontake);
}
	public:
	int minCoins(vector<int> &coins, int n, int sum) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    int ans = solve(coins,n,sum,dp);
	    if(ans == INT_MAX-1)
	    {
	        return -1;
	    }
	    else
	    {
	        return ans;
	    }
	    
	    
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends