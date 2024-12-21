class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        for (int i: nums) {
            if (!(i%2))m[i]++;
        }
        int maxiCnt = 0, maxi = 0 ;
        for (auto& i: m) {
            if (i.second > maxiCnt) {
                maxiCnt = i.second;
                maxi = i.first;
            }
        }
        return maxiCnt==0? -1: maxi;
        
    }
};