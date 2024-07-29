//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int mod = 1e9+7;

    int countSubsetSum(vector<int>& arr, int sum, int n, vector<vector<int>>& dp) {
        // Base cases
        if (n == 0) {
            if (sum == 0 && arr[0] == 0) {
                return 2;
            }
            if (sum == 0 || sum == arr[0]) {
                return 1;
            }
            return 0;
        }

       
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }

        int notTake = countSubsetSum(arr, sum, n-1, dp) % mod;

        int take = 0;
        if (arr[n] <= sum) {
            take = countSubsetSum(arr, sum-arr[n], n-1, dp) % mod;
        }

        return dp[n][sum] = (take + notTake) % mod;
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

       
        if ((sum - d) % 2 != 0 || (sum - d) < 0) {
            return 0;
        }

        int subsetSum = (sum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, -1));
        return countSubsetSum(arr, subsetSum, n-1, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends