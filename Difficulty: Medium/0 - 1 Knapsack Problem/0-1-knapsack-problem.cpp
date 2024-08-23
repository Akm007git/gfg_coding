//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int solve(int n,int w,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp)
    {
        if(n == 0 || w == 0) return 0;
        if(dp[n-1][w-1] != -1) return dp[n-1][w-1];
        
        // choice
        if(wt[n-1] <= w)
        {
            return dp[n-1][w-1] = max(val[n-1] + solve(n-1,w - wt[n-1],wt,val,dp),solve(n-1,w,wt,val,dp));
        }
        else
        {
            return dp[n-1][w-1] = solve(n-1,w,wt,val,dp);
        }
    }
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        
        int n = wt.size();
        
        vector<vector<int>>dp(n,vector<int>(w,-1));
        return  solve(n,w,wt,val,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends