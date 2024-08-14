//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:
    void solve(int row, int col, int n, string str, vector<vector<int>>& matrix, vector<string>& ans, vector<vector<bool>>& visited, int delRow[], int delCol[], string &direction) {
        // Base case: Reached the destination
        if (row == n-1 && col == n-1) {
            ans.push_back(str);
            return;
        }

        // Exploring all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check if the move is valid and the cell is not visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol] && matrix[nrow][ncol] == 1) {
                // Mark the cell as visited
                visited[nrow][ncol] = true;
                
                // Recursively solve for the next cell
                solve(nrow, ncol, n, str + direction[i], matrix, ans, visited, delRow, delCol, direction);
                
                // Backtrack: Unmark the cell as visited
                visited[nrow][ncol] = false;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>>& matrix) {
        vector<string> ans;
        int n = matrix.size();
        if (n == 0) return ans;  // Edge case: empty matrix
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int delRow[] = {1, 0, 0, -1};  // Down, Right, Left, Up
        int delCol[] = {0, 1, -1, 0};  // Down, Right, Left, Up
        string direction = "DRLU";     // Directions mapped to the above movements

        // If the start cell is open, begin the search
        if (matrix[0][0] == 1) {
            visited[0][0] = true;  // Mark the starting cell as visited
            solve(0, 0, n, "", matrix, ans, visited, delRow, delCol, direction);
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends