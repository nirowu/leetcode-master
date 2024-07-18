class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int maxDist = -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        // Initialize the queue with all land cells and set their distances to 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        if (q.empty() || q.size() == rows * cols) return -1;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            pair<int, int> pii = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = pii.first + dx[k];
                int y = pii.second + dy[k];
                if (x >= 0 && x < rows && y >= 0 && y < cols && dist[x][y] == -1) {
                    dist[x][y] = dist[pii.first][pii.second] + 1;
                    maxDist = max(maxDist, dist[x][y]);
                    q.push({x, y});
                }
            }
        }
        return maxDist;
    }
};