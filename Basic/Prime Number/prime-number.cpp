//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int n){
        // code here
        int count   = 0;
        for(int i = 1; i*i<= n ;i++)
        {
            if(n%i == 0)
            {
                count++;
                
                
                // handle the back side case suppose n = 34, 2*17 = 34 also 17*2 = 34
                // here handelinh the last acase
                
                if(n/i && n/i != i)
                {
                    count++;
                }
            }
        }
        
        return count == 2 ? true : false;
        
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends