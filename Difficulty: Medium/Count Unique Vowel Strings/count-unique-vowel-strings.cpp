class Solution {
    
    private:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    private:
    long long factorial(int n)
    {
        if(n == 0 || n == 1)
        {
            return 1;
        }
        
        return n*factorial(n-1);
    }
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            if(isVowel(it))
            {
                mp[it]++;
            }
        }
        
        // now calculate the ans
        if(mp.size() == 0) return 0;
        int ans = factorial(mp.size());
        
        // but if multiple vowel exist
        for(auto it:mp)
        {
            if(it.second > 1)
            {
                ans = ans*it.second;
            }
        }
        
        return ans;
        
    
        
    }
};