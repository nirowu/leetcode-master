class Solution {
public:
    int dp[205] = {};
    int m, n;
    int largestRectangleArea() {
        stack<int> st; // 用來存放索引的棧
        int maxArea = 0; // 初始化最大面積
        dp[n] = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && dp[st.top()] > dp[i]) {
                int height = dp[st.top()]; // 取出棧頂高度
                st.pop(); // 移除棧頂
                int width = st.empty() ? i : i - st.top() - 1; // 計算寬度
                maxArea = max(maxArea, height * width); // 更新最大面積
            }
            st.push(i); // 將當前索引壓入棧
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxiArea = 0;
        for (int j = 0; j < n; j++) { // i = 0
            dp[j] = matrix[0][j] == '1' ? 1 : 0;
            maxiArea = max(maxiArea, largestRectangleArea());
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = matrix[i][j] == '1' ? (1 + dp[j]) : 0;
            }
            maxiArea = max(maxiArea, largestRectangleArea());
        }
        return maxiArea;
    }
};