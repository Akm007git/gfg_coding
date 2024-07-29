//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    
    bool subsetSum(int arr[],int sum,int n,vector<vector<int>>&dp)
    {
        // base case
        if(sum  == 0)
        {
            return 1;
        }
        if(n == 0)
        {
            return 0;
        }
        // memoize
        if(dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        
        // choice diagram
        if(arr[n-1] <= sum)
        {
            return dp[n][sum] = subsetSum(arr,sum-arr[n-1],n-1,dp) || subsetSum(arr,sum,n-1,dp);
        }
        else
        {
            return dp[n][sum] = subsetSum(arr,sum,n-1,dp);
        }
        
        
    }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0;i<n;i++)
	    {
	        sum  += arr[i];
	    }
	    
	    vector<bool>check(sum/2,false);
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    for(int i = 0;i<sum/2+1;i++)
	    {
	        check[i] = subsetSum(arr,i,n,dp); // that means this subset sum is possible
	    }
	    
	    //  all the last row's value will be stored here as true or false
	    
	    int ans = INT_MAX;
	    for(int i = 0;i<check.size()+1;i++)
	    {
	        if(check[i])
	        {
	            ans = min(ans,sum - 2*i);
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