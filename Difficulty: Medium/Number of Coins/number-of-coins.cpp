//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

// mamo
// private:
// int solve(vector<int>&coins,int n,int sum,vector<vector<int>>&dp)
// {
//     // base case
//     if(sum == 0)
//     {
//         return 0;
//     }
//     if(n == 0)
//     {
//         return INT_MAX-1;
//     }
    
//     // memo
//     if(dp[n][sum] != -1)
//     {
//         return dp[n][sum];
//     }
    
//     // choice diagram
//     if(coins[n-1] <= sum)
//     {
//         return dp[n][sum] =  min( (1 + solve(coins,n,sum-coins[n-1],dp)),
//                             solve(coins,n-1,sum,dp) );
//     }
//     else
//     {
//       return dp[n][sum] = solve(coins,n-1,sum,dp);
//     }
    
//   // return dp[n][sum] = min(take,nontake);
// }

// tabu

private:
int solve(vector<int>&coins,int n,int sum,vector<vector<int>>&dp)
{
    // initiali
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j<sum+1;j++)
        {
            
            if( j == 0)
            {
                dp[i][j] = 0;
            }
            if(i == 0)
            {
                dp[i][j] = INT_MAX-1;
            }
            
            
        }
    }
    
    // 2nd row initialization
    //   for (int j = 1; j < sum + 1; j++) {
    //     if (j % coins[0] == 0) {
    //         dp[1][j] = j / coins[0];
    //     } else {
    //         dp[1][j] = INT_MAX - 1;
    //     }
    // }
    
    // choice diaga
    
    for(int i = 1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coins[i-1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    //  if(dp[n][sum]==INT_MAX-1)
    //         return -1;
    //     else
       return dp[n][sum];
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