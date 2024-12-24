class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       // number of rows
        int n = matrix[0].size();    // number of columns
        int row = 0, col = n - 1;   // Start from the top-right corner

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;  
            } else {
                col--;  
            }
        }
        return false;  
    }
};
