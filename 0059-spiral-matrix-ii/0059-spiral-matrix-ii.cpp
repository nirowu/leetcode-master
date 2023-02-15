class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int top = 0;
        
        int right = n - 1;
        int down = n  - 1;
        
        int matSize = n * n;
        vector<int>arr(n);
        vector<vector<int>>mat(n, arr);
        int cnt = 1;

        while(left < right && top < down) {
            for (int i = left; i < right; i++) {
                mat[top][i] = cnt++; 
            }
            for (int i = top; i < down; i++) {
                mat[i][right] = cnt++;
            }
            for (int i = right; i > left; i--){
                mat[down][i] = cnt++;
            }
            for (int i = down; i > top; i--){
                mat[i][left] = cnt++;
            }
            left++; top ++;
            right--;down --; 
        }
        int mid = n/2;
        if (n%2) {mat[mid][mid] = cnt;}
        
        return mat;
    }
};