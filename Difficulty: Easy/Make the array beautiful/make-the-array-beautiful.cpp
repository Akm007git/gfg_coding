//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) 
    {
        vector<int>v;
        stack<int>st;
        int n = arr.size();
        
        for(int i = 0;i<n;i++)
        {
            int value  = arr[i];
            
            if(st.empty())
            {
                st.push(value);
            }
            else // non empty
            {
                if((st.top() >= 0 && value < 0) ||
                    (st.top() < 0 && value >= 0))
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(value);
                    }
            }
        }
        // all are ready oin stack
      while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
}
;

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends