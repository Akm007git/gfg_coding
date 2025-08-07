class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        
        vector<int> seconds;
        
        // Convert each time to total seconds
        for (const string& time : arr) {
            int h = stoi(time.substr(0, 2));  // hours
            int m = stoi(time.substr(3, 2));  // minutes
            int s = stoi(time.substr(6, 2));  // seconds
            seconds.push_back(h * 3600 + m * 60 + s);
        }
        
        sort(seconds.begin(), seconds.end());
        
        int min_diff = INT_MAX;
        
        // Compare adjacent times
        for (int i = 1; i < seconds.size(); ++i) {
            min_diff = min(min_diff, seconds[i] - seconds[i-1]);
        }
        
        // Wrap-around check (critical part)
        int wrap_diff = (seconds.front() + 86400) - seconds.back();
        min_diff = min(min_diff, wrap_diff);
        
        return min_diff;
        
    }
};
