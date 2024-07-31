//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    int solve(string &s,string &p,int m,int n,vector<vector<int>>&dp)
    {
        // base
        if( m == 0 || n == 0)
        {
            return 0;
        }
        // memo
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        
        // choice diag
        if(s[m-1] == p[n-1] && (m-1) != (n-1))
        {
            return dp[m][n] = 1 + solve(s,p,m-1,n-1,dp);
        }
        else
        {
            return dp[m][n] = max(solve(s,p,m-1,n,dp) , solve(s,p,m,n-1,dp));
        }
        
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    string str2 = str;
		    int m = str.size();
		    int n = m;
		    
		    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
		    
		    return solve(str,str2,m,n,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends