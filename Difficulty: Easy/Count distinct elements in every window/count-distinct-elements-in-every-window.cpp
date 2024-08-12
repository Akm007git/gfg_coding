//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int nums[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        vector<int>v;
        
        // calculate the first window
        for(int  i = 0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        v.push_back(mp.size());
        
        // othehrs window
        for(int i = k;i<n;i++)
        {
           int prevElement = nums[i-k];
           mp[prevElement]--; // decrese the count
           
           // If fre is 0 that means only one chilo, we have to remove it and add next elemnt in amap
           // if freq not 0 it means in the middlle of array somewhere another  count avialble that will contribute to the next window
           
           if(mp[prevElement] == 0)
           {
               mp.erase(prevElement);
           }
           // one step move forward
           mp[nums[i]]++;
           
           v.push_back(mp.size());
        }
        
        return v;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends