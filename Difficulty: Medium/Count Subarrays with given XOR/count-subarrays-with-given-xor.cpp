//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int prefixXor = 0;
        long count = 0;

        for (int num : arr) {
            // Update prefix XOR
            prefixXor ^= num;

            // If prefixXor itself is equal to k, increment count
            if (prefixXor == k) {
                count++;
            }

            // Check if there exists a prefixXor[i-1] such that:
            // prefixXor[i-1] = prefixXor[j] ⊕ k
            int target = prefixXor ^ k;
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }

            // Update the frequency of the current prefixXor
            freq[prefixXor]++;
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends