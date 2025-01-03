//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void insertButton(stack<int> &st,int element)
    {
        // base
        if(st.empty())
        {
            st.push(element);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        insertButton(st,element);
        st.push(top);
    }
public:
    void Reverse(stack<int> &st){
        
        if(st.empty())
        {
            return;
        }
        
        int top = st.top();
        st.pop();
        
        Reverse(st);
        
        return insertButton(st,top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends