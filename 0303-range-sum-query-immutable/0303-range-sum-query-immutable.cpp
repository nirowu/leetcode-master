class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        long long cnt = 0;
        this->sum.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            cnt += nums[i];
            this->sum.push_back(cnt);
        }
    }
    
    int sumRange(int left, int right) {
        return this->sum[right+1] - this->sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */