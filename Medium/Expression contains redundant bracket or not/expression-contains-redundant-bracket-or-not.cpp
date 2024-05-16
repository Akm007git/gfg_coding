//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if( s[i] == '(' ||
                s[i] == '+' || 
                s[i] == '-' || 
                s[i] == '*' || 
                s[i] == '/'  )
                {
                    st.push(s[i]); // push all these elemnt;
                }
                
            if(s[i] == ')')
            {
                if( st.top() == '(' ) // it means therse no special charecter between open and close brackets
                {
                    return 1; // is redundant true;
                }
                else // got special char
                {
                    while(st.top() != '(')
                    {
                        st.pop();
                    }
                    // got the opening bracket , but it s not use less as in middlel special char availbale
                    
                    st.pop(); // pop that opening brack for  
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends