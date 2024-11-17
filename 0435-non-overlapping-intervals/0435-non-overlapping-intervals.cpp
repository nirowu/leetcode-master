class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1, ans = 0;
        while( j < intervals.size()) {
            if (intervals[i][1] <= intervals[j][0]) {
                // cout<<intervals[i][1]<<intervals[j][0]<<endl;
                i = j;
                // cout<<"1"<<endl;
            } // 12 34
            else if (intervals[i][1] <= intervals[j][1]){
                // cout<<intervals[i][1]<<intervals[j][0]<<endl;

                ans++;
                // cout<<"2"<<endl;

            } // 13 2
            else if (intervals[i][1] > intervals[j][1]){
                i = j;
                ans++;
                // cout<<"3"<<endl;

            } // 12 12
            j++;
        }
        return ans;
        
    }
};