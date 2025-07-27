class Solution {
    
    private:
    void fillRow(vector<vector<int>> &matrix,int row,int m)
    {
        for(int i = 0;i<m;i++)
        {
            if(matrix[row][i] != 0)
            {
                matrix[row][i] = 0;
            }
        }
    }
    
    
    private:
    void fillCol(vector<vector<int>> &matrix,int col,int n)
    {
        for(int i = 0;i<n;i++)
        {
            if(matrix[i][col] != 0)
            {
               matrix[i][col] = 0; 
            }
        }
    }
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(); // row
        int m = mat[0].size(); // col
        
        // create a copy matrix
        vector<vector<int>>copy = mat;
        
        // traverse the matrix
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(copy[i][j] == 0)
                {
                    fillRow(mat,i,m);// fix row, just col will be diff
                    fillCol(mat,j,n); // fix col, row will be diff
                }
            }
        }
        
    }
};