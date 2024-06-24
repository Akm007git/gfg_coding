//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    private:
    void reversing(int arr[],int i,int j)
    {
        while(i<=j)
        {
            swap(arr[i],arr[j]);
            i++,j--;
        }
    }
    
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
         d = d%n;
        // reversing(arr,0,d-1);
        // reversing(arr,d,n-1);
        // reversing(arr,0,n-1
        
        // separate ans
        
         reverse(arr,arr+d);
        reverse(arr+d,arr+n);
        reverse(arr,arr+n);
        
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends