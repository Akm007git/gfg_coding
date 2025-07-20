class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
            int total = 9 * pow(10, n - 1);

    // Create a set of excluded digits for quick lookup
    unordered_set<int> excluded(arr.begin(), arr.end());

    // Calculate first digit options (1-9, not in excluded)
    int first_digit_options = 0;
    for (int d = 1; d <= 9; ++d) {
        if (excluded.find(d) == excluded.end()) {
            first_digit_options++;
        }
    }

    // Calculate other digit options (0-9, not in excluded)
    int other_digit_options = 0;
    for (int d = 0; d <= 9; ++d) {
        if (excluded.find(d) == excluded.end()) {
            other_digit_options++;
        }
    }

    // Calculate numbers with no digits from arr
    int no_digits_from_arr = first_digit_options * pow(other_digit_options, n - 1);

    // Result is total - no_digits_from_arr
    return total - no_digits_from_arr;
    }
};
