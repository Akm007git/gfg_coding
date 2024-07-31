//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		private:
		int solve(string &s1,string &s2,int m,int n,vector<vector<int>>&dp)
		{
		    //base
		   for(int i = 0;i<m+1;i++)
		   {
		       for(int j = 0;j<n+1;j++)
		       {
		           if(i == 0 || j == 0)
		           {
		               dp[i][j] = 0;
		           }
		       }
		   }
		   // choice diagram
		   for(int i=1;i<m+1;i++)
		   {
		       for(int j = 1;j<n+1;j++)
		       {
		           if(s1[i-1] == s2[j-1])
		           {
		               dp[i][j] = 1 + dp[i-1][j-1];
		           }
		           else
		           {
		               dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		           }
		       }
		   }
		   return dp[m][n];
		}

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
	    int length = solve(str1,str2,m,n,dp);
	    
	   
	   int deletion = (m - length); // deletion
	    int insertion = ( n-length); //insertion
	    
	    return (insertion + deletion);
	   
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends