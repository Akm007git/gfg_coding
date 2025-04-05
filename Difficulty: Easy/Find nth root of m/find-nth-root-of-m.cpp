//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    
    int getValue(int power,int digit,int target)
    {
        int ans  = 1;
        
        for(int i = 1;i <= power;i++)
        {
            ans = ans*digit;
            
            if(ans > target) return 2;
        }
        
        if(ans  == target) return 1;
        return 0;
    }
    
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int start = 1;
        int end = m;
        
        if(n == 1)
        {
            return m;
        }
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            
            int check = getValue(n,mid,m);
            
            if(check == 1) return mid;
            else if(check == 0) start = mid+1;
            else end = mid - 1;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends