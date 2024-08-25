//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int s  = 0;
        int e = n - 1;
        
        while(s < e)
        {
            int mid = (s + e)/2;
            
            // check which part will be sorted
            //step:1  if left part is sorted
            if(arr[s] <= arr[mid])
            {
                if(arr[s] <= arr[e])
                {
                    return s;
                }
                // go to the right
                s = mid+1;
            }
            else // right sorted
            {
                // go to left
                e = mid;
            }
        }
        
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends