//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

private:
    int modifiedSubset(int arr[],int n,int sum,vector<vector<int>>&dp)
    {
        // base case
      if(n == 0 && sum != 0) return 0;
      if(n == 0 && sum == 0) return 1;
      
      // memo
      if(dp[n][sum] != -1)
      {
          return dp[n][sum];
      }
        if(arr[n-1] <= sum)
        {
            return dp[n][sum] =  (modifiedSubset(arr,n-1,sum-arr[n-1],dp) % mod + modifiedSubset(arr,n-1,sum,dp)%mod)%mod ; 
        }
        else
        {
            return modifiedSubset(arr,n-1,sum,dp)%mod;
        }
    }
	public:
	int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
	    
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    return modifiedSubset(arr,n,sum,dp);

	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends