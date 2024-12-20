class Solution {
public:
    int n;
    vector<vector<int>> paths;
    void helper(vector<vector<int>>& graph, int cur, vector<int>path) {
        path.push_back(cur);
        if (cur == n - 1) {
            paths.push_back(path);
            return;
        } else {
            for (int i = 0; i < graph[cur].size(); i++) {
                helper(graph, graph[cur][i], path);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        helper(graph, 0, {});
        return paths;
    }
};