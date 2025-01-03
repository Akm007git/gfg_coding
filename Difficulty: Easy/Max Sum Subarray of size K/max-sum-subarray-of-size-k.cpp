//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        
          // calculate the fisrt fix window
        long sum = 0;
        long maxSum = LONG_MIN;
        for(int i = 0;i<K;i++)
        {
            sum += Arr[i];
        }
        
        maxSum = max(sum,maxSum);
        
        // process for other windoe
        
        for(int i = K;i<N;i++)
        {
            sum += Arr[i]; // adding one step ager eleemnt and add to eleemnt
            sum -= Arr[i-K]; // removing prev elemt from the first
            
            maxSum = max(sum,maxSum);
            
        }
        
        return maxSum;
      
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends