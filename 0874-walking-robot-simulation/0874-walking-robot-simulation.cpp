class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, int> map;
        for (auto it: obstacles) {
            string key = to_string(it[0])+"+"+to_string(it[1]);
            map[key]++;
            
        }
        
        int rob_x = 0, rob_y = 0;
        int tar_x = 0, tar_y = 0;

        int dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int maximun_distance = 0;
        for (int i: commands) {
            if (i == -1) {
                dir = (dir+1) % 4; continue;
            }
            else if (i == -2) {
                dir = (dir-1+4) % 4; continue;
            }
            else {
                while(i--) {
                    tar_x = rob_x + dx[dir];
                    tar_y = rob_y + dy[dir];
                    
                    string tar = to_string(tar_x)+"+"+to_string(tar_y);
                    if (map.find(tar) != map.end()) {
                        break;
                    }
                    else {
                        rob_x = tar_x;
                        rob_y = tar_y;
                    }
                }
                int temp = (pow(rob_x, 2) + pow(rob_y, 2));
                maximun_distance = max(maximun_distance, temp);
            } 
            
        }
        return maximun_distance;
    }
};