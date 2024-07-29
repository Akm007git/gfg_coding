//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    private:
    bool solve(vector<int>&arr,int sum,int n,vector<vector<int>>&dp)
    {
        // base initialization
        for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<sum+1;j++)
            {
                if(i == 0) // n jodi1,2,3,4, sum  0 ki possible no its not
                {
                    dp[i][j] = 0;
                }
                if(j == 0) // sum 0 kora possible
                {
                    dp[i][j] = 1;
                }
            }
        }
        
        // choice diagram
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 0;j<sum+1;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; // take || mnot take
                }
                else
                {
                    dp[i][j] = dp[i-1][j]; // only not take
                }
            }
        }
        
        return dp[n][sum];
        
    }
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // Tabulization
        int n  = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        
        return solve(arr,sum,n,dp);
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends