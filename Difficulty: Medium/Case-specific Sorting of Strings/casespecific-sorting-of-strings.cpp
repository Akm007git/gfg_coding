class Solution {
  public:
    string caseSort(string& str) {
        // code here
        string upper = "";
        string lower = "";
        
        for(auto it:str)
        {
            if(it >= 'A' && it <= 'Z' )
                upper += it;
            else
                lower += it;
        }
        
        // sort them
        sort(upper.begin(),upper.end());
        sort(lower.begin(),lower.end());
        
        // now allign them
        int i = 0; int j = 0;
        string ans = "";
        for(auto it:str)
        {
            if(it >= 'A' && it <= 'Z' )
                ans += upper[i++];
            else
                ans += lower[j++];
        }
        
        return ans;
        
    }
};