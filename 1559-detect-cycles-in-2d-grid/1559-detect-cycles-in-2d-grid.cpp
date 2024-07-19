class Solution {
public:
    int visited[505][505] = {0};
    int start[505][505] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    
    bool dfs (vector<vector<char>>& grid, int i, int j, int x, int y) {
        bool isCycle = false;
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            if (newX >= 0 && newY >=0 && newX < m && newY < n) {
                if (grid[newX][newY] == grid[i][j]) {
                    if (newX == x && newY == y) { 
                        continue; 
                    }
                    if (visited[newX][newY]) {
                        return true;
                    }
                    else {
                        isCycle |= dfs(grid, newX, newY, i, j);
                    }
                }
            }

        }
        return isCycle;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) return true; 
                }
            }
        }
        return false;
    }
};