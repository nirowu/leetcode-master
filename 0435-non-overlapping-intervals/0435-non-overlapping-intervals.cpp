class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1, ans = 0;
        while( j < intervals.size()) {
            if (intervals[i][1] <= intervals[j][0]) {
                i = j;
            } 
            else if (intervals[i][1] <= intervals[j][1]){
                ans++;
            } 
            else if (intervals[i][1] > intervals[j][1]){
                i = j;
                ans++;
            } 
            j++;
        }
        return ans;
        
    }
};