//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int findLps(string &s,string &p,int m,int n,vector<vector<int>>&dp)
{
    //initi
    for(int i = 0;i<m+1;i++)
    {
        for(int j = 0;j<n+1;j++)
        {
            if( i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    // choice diagr
    
    for(int i = 1;i<m+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            if(s[i-1] == p[j-1] )
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string s = str;
    reverse(str.begin(),str.end());
    int m = n;
   
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    int length = findLps(s,str,n,m,dp);
    return  n - length;
} 