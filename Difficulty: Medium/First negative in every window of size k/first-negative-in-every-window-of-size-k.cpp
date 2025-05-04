//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int>ans;
        deque<int>dq;
        
        int i = 0;
        int j = 0;
        while(j < n)
        {
            // if j neg, then store in the queue
            if(arr[j] < 0)
            {
                dq.push_back(arr[j]);
            }
            
            // if got the window
            if(j-i+1 == k)
            {
                //if any neg in the dq,stote that
                if(!dq.empty())
                {
                    ans.push_back(dq.front());
                }
                else
                {
                    ans.push_back(0);
                }
                
                // we nee d to move the i, but but check if i == dq.top then pop it, becuse we sliding the window right
                if(arr[i] == dq.front() && !dq.empty())
                {
                    dq.pop_front();
                }
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends