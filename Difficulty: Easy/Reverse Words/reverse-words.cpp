//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.size();
        string ans  = "";
        string temp = "";
        for(int i = n-1;i>=0;i--)
        {
            if(S[i] != '.')
            {
                temp += S[i];
            }
            else
            {
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += '.';
                
                temp = "";// for next
            }
        }
        
        if(temp.size())
        {
            reverse(temp.begin(),temp.end());
            ans += temp;
        }
       // cout<<ans<<endl;
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends