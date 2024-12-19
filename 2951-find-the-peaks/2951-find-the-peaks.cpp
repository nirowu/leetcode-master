class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        int m = mountain.size() ;
        for (int i = 1; i < m-1; i++) {
            if ((mountain[i] > mountain[i-1]) && (mountain[i] > mountain[i+1])) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};