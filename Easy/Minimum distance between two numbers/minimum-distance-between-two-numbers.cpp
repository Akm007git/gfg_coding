//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
        int ans = INT_MAX;
        int a = -1; int b = -1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
                a = i; // for this we get the first occereneces also store that
            if(arr[i] == y)
                b = i; // for this we get the first occereneces also store that
           if(a != -1 && b != -1)
           {
                ans = min(ans,abs(a-b));
           }
        }
        
        if(ans == INT_MAX )
        {
            return -1;
        }
       
            return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends