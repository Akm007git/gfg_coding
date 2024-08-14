//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        
        int minimum = 0;
        int buy = 0;
        int free = N-1;
        
        while(buy <= free)
        {
            minimum += candies[buy]; // ad dthe mnimum value
            buy++;
            free = free - K; // taking from last
        }
        
        int maximum = 0;
        buy = N-1;
        free = 0;
        
        while(free <= buy)
        {
            maximum += candies[buy];
            buy--;
            
            free = free + K;
        }
        
        return {minimum,maximum};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends