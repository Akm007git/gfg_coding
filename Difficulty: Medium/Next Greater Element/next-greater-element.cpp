//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long >v;
        stack<long long >st;
       
        
        for(int i = n-1;i>=0;i--)
        {
            long long int current = arr[i];
            
            while(!st.empty() && st.top() <= current )
            {
                st.pop();
            }
            if(st.empty()) // mena no freter n the right side
            {
                v.push_back(-1);
            }
            else // got the greater eleemnt
            {
                v.push_back(st.top());
            }
            
            st.push(current); // posibility it coulb be a greater of some one
        }
        
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends