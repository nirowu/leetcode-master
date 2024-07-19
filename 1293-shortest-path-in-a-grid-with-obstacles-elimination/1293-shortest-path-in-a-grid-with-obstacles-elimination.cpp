class Solution {
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size(); n = grid[0].size();
        if (k >= m + n - 3)  return m + n - 2;
        vector<vector<int>> mincost(m + 1, vector<int>(n + 1, k + 1));
        
        // r, c, d, cost
        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, 0, 0});
        while(!q.empty()) {
            auto [r, c, d, cost] = q.front(); q.pop();
            if (r == m - 1 &&  c == n-1) return d;
            for (int i = 0; i < 4; i++) {
                int newr = r + dx[i];
                int newc = c + dy[i];
                if (newr >= 0 && newc >= 0 && newr < m && newc < n) {
                    int curCost = cost + grid[newr][newc];
                    if (curCost < mincost[newr][newc]) {
                        q.push({newr, newc, d + 1, curCost});
                        mincost[newr][newc] = curCost;
                    }
                }
            }


        }
        return -1;
    }
};