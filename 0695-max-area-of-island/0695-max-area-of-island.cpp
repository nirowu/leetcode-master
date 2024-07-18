
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j) {

        int area = 0, x, y;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        grid[i][j] = -1;
        
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()) {
            pair<int, int> pii = q.front();
            for (int k = 0; k < 4; k++) {
                x = pii.first + dx[k];
                y = pii.second + dy[k];
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()                              && grid[x][y] == 1) {
                    grid[x][y] = -1;
                    q.push({x, y});
                }

            }
            q.pop();
            area++;
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }
        

        return maxArea;
    }
};