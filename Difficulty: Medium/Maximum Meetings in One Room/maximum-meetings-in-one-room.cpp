//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    static bool comp(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b)
    {
        if(a.second.second != b.second.second)
        {
            return a.second.second < b.second.second;
        }
        
        return a.first < b.first;
    }
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<pair<int,pair<int,int> >>v;
        vector<int>ans;
        
        for(int i = 0;i<S.size();i++)
        {
            pair<int,pair<int,int>>p = {i+1,{S[i],F[i]}};
            v.push_back(p);
        }
        
        //pair ready
        
        sort(v.begin(),v.end(),comp);
        
        int ansEnd = v[0].second.second; // setching thr fist and end
        ans.push_back(v[0].first);// intially for first meeting
        
        for(int i = 1;i<S.size();i++)
        {
            if(v[i].second.first > ansEnd)
            {
                ans.push_back(v[i].first);
                ansEnd = v[i].second.second;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends