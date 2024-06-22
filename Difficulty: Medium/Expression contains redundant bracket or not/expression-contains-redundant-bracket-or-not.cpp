//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(' ||
               s[i] == '+' ||
               s[i] == '-' ||
               s[i] == '*' ||
               s[i] == '/' )
               {
                   st.push(s[i]);
               }
               
                if(s[i] == ')') // means close bracket
                {
                   if(st.top() == '(')
                   {
                       return 1; // it means no char in bwteen open and close so extra bracket avail
                   }
                   else // all are charecter
                   {
                       // then we have to taverse til, we got ( and delete that
                       
                       while(st.top() != '(')
                       {
                         
                           st.pop();
                       }
                       // got the open bracket
                       // delete that
                       // means this portion no  redudancy
                       
                       st.pop();
                   }
               }
        }
          return 0;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends