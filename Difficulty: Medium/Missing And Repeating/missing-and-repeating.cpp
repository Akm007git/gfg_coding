//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int mod = 1e9+8;
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        int rept = 0;
        
        for(auto it:mp)
        {
            if(it.second > 1)
            {
                rept = it.first;
                break;
            }
        }
        
 
        
        // int totalSum = n * (n+1)/2;
        // //cout<<totalSum<<" ";
        
        // int sum = 0;
        // for(int i = 0;i<n;i++)
        // {
        //         sum += arr[i];
        // }
        
        // sum = sum - rept; // for omiting thr repaet number
        
        // int missing  = (totalSum % mod - sum % mod)%mod;
        
        int missing  = 0;
        for(int i = 1;i<=n;i++)
        {
            if(mp.find(i) == mp.end()) // means if i not exist in map, that means it could be an eleemnt
            {
                missing = i;
                break;
            }
        }
        return {rept,missing};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends