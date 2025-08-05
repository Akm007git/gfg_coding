class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n = s.size();
        string str  = "";
        
        for(int i = 0;i<n;i++)
        {
            char ch = tolower(s[i]);
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                str += ch;
            }
            else
            {
                continue;
            }
            
        }
        
        //cout<<str<<endl;
        // reverse the string
        
        string str2 = str;
        reverse(str.begin(),str.end());
        if(str == str2) return true;
        else return false;
        
    }
};