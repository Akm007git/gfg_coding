//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    private:
    int solve(int w,int wt[],int val[],int n,vector<vector<int>>&dp)
    {
        if( n == 0 || w == 0)
       {
           return 0;
       }
       
       
       //memo
       if(dp[w-1][n-1] != -1)
       {
           return dp[w-1][n-1];
       }
       // choice d
       if(wt[n-1] <= w) // taking
       {
           return dp[w-1][n-1] =  max( val[n-1] + solve(w-wt[n-1],wt,val,n-1,dp), solve(w,wt,val,n-1,dp)); 
       }
       else // not taking
       {
           return dp[w-1][n-1] =  solve(w,wt,val,n-1,dp);
       }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //base case
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       
       return solve(W,wt,val,n,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends