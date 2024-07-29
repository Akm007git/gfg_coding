//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    
//  bool subsetSum(int arr[], int sum, int n, vector<vector<int>>& dp) {
//     // Base case
//     if (sum == 0) {
//         return true;
//     }
//     if (n == 0) {
//         return false;
//     }

//     // Memoization check
//     if (dp[n][sum] != -1) {
//         return dp[n][sum];
//     }

//     // Choice diagram
//     if (arr[n-1] <= sum) {
//         dp[n][sum] = subsetSum(arr, sum - arr[n-1], n-1, dp) || subsetSum(arr, sum, n-1, dp);
//     } else {
//         dp[n][sum] = subsetSum(arr, sum, n-1, dp);
//     }

//     return dp[n][sum];
// }

    
    //
    bool subsetSum(int arr[],int sum,int n,vector<vector<int>>&dp)
    {
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<sum+1;j++)
            {
                if(i == 0)
                {
                    dp[i][j] = 0;
                }
                if( j == 0)
                {
                    dp[i][j]  = 1;
                }
            }
        }
        
        // choice diag
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<sum+1;j++)
            {
                if(arr[i-1] <= j)
                {
                     dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }

  public:
	int minDifference(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Initialize dp array with -1
    vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, -1));
    
    // Call the subsetSum function to fill the dp array
    subsetSum(arr, sum / 2, n, dp);

    // Find the minimum difference
    int ans = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n][i]) {
            ans = min(ans, sum - 2 * i);
        }
    }
    return ans;
}
	
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends