//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int m = pat.size(); //short
        int n = txt.size(); //long
        
        if( m > n) return 0;
        vector<int>freq(26,0);
        for(auto it:pat)
        {
            freq[it - 'a']++; // ca to aschii and store it int the ffreq array
        }
        
        vector<int>window(26,0);
        for(int i = 0;i<m;i++)
        {
            char ch = txt[i];
            window[ch - 'a']++;
        }
        
        int count  = 0;
        
        if(freq == window) count++;
        
        // basically first window mapping done
        
        // check for the rest of the window
        for(int i = m;i<n;i++)
        {
            // remove one , add one
            //removig the forst part
            char remove = txt[i - m];
            window[remove - 'a']--;
            
            // adding the current  element
            char add = txt[i];
            window[add - 'a']++;
            
            // check whether the freq is same or not
            if(freq == window) count ++;
            
        }
        
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends