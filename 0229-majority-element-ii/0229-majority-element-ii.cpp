class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int lowestBound = nums.size()/3;
        int cnt = 0;
        vector<int> ans;
        set<int> s;
        unordered_map<int, int> m;
        for (int i: nums) {
            m[i]++;
            if ((m[i] > lowestBound) && s.find(i) == s.end()) {
                ans.push_back(i);
                s.insert(i);
            }
        }
        return ans;
    }
};