//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int n,int w,int val[],int wt[],vector<vector<int>>&dp)
    {
         if(n == 0 || w == 0)
        {
            return 0;
        }
        
        // memo
        if(dp[n][w] != -1)
        {
            return dp[n][w];
        }
        
        // process
        if(wt[n-1] <= w)
        {
            return dp[n][w] =  max(val[n-1] + solve(n,w-wt[n-1],val,wt,dp),solve(n-1,w,val,wt,dp) );
        }
        else
        {
            return  dp[n][w] = solve(n-1,w,val,wt,dp);
        }
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return solve(N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends