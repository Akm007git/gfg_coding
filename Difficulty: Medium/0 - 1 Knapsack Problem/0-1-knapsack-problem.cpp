//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
       int  dp[1002][1002];
     Solution() {
        memset(dp, -1, sizeof(dp));
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W == 0 || n == 0)
       {
           return 0;
       }
       
       if(dp[W][n]  !=  -1)
       {
           return dp[W][n];
       }
       // recursive call according choice diagram
       if(wt[n-1] <= W)
       {
           return  dp[W][n] =  max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1),
                      knapSack(W,wt,val,n-1));
       }
       else if(wt[n-1] > W)
       {
           return  dp[W][n] = knapSack(W,wt,val,n-1);
       }
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