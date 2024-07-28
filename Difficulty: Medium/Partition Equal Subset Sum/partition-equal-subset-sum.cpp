//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    bool subSet(int arr[],int n,int sum)
    {
        // base case
        if( n == 0)
        {
            return false;
        }
        if(sum == 0)
        {
            return true;
        }
        
        // recursive sol
        if(arr[n-1] <= sum)
        {
            return subSet(arr,n-1,sum-arr[n-1]) || subSet(arr,n-1,sum);
        }
        else
        {
            return subSet(arr,n-1,sum);
        }
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum  = 0;
        for(int i = 0;i<N;i++)
        {
            sum += arr[i];
        }
        
        if(sum % 2 != 0)
        {
            return false;
        }
        else
        {
            return subSet(arr,N,sum/2);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends