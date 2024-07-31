//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    private:
    int solve(string &s1,int m,string &s2,int n,vector<vector<int>>&dp)
    {
        // base
        if(m == 0 || n == 0)
        {
            return 0 ;
            
        }
        // memo
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        
        // recursive
        if(s1[m-1] == s2[n-1])
        {
            return dp[m][n] = 1 + solve(s1,m-1,s2,n-1,dp);
        }
        else
        {
            return dp[m][n] = max( solve(s1,m,s2,n-1,dp),solve(s1,m-1,s2,n,dp));
        }
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int length = solve(X,m,Y,n,dp);
        int ans  = (m+n) - length;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends