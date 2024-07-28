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
        // base
        if(sum == 0)
        {
            return true; // n jekono hok na keno sum == 0 easily kora jabe thats why true
        }
        if(n == 0)
        {
            return false;
        }
        
        if(dp[n][sum] != -1 )
        {
            return dp[n][sum];
        }
        
        // recursibve sol
        
        if(arr[n-1] <= sum) // traversing from backward
        {
            // take ot not take
            return dp[n][sum] = solve(arr,sum - arr[n-1] , n-1,dp) || solve (arr,sum,n-1,dp) ;
        }
        else // if greater then the sum then not take
        {
            return dp[n][sum] =  solve(arr,sum,n-1,dp);
        }
    }
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // MEMO IZATION
        int n  = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
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