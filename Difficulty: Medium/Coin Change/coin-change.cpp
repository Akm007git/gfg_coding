//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    long long int solve(int coins[],int n,int sum,vector<vector<long long int>>&dp)
    {
        // base case
        if(sum  == 0)
        {
            return 1;
        }
        if(n == 0  )
        {
            return 0;
        }
        
        // memeo
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        
        // recur
        if(coins[n-1] <= sum)
        {
            return dp[n][sum] = ( solve(coins,n,sum-coins[n-1],dp) +  solve(coins,n-1,sum,dp));
        }
        else
        {
            return dp[n][sum] =  solve(coins,n-1,sum,dp);
        }
    }
  public:
    long long int count(int coins[], int n, int sum) {

        vector<vector<long long int>>dp(n+1,vector<long long int>(sum+1,-1));
        // code here.
       return solve(coins,n,sum,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends