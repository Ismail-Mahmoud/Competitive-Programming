// https://leetcode.com/problems/predict-the-winner/

class Solution {
    int mem[20][20], sum[20];
public:
    bool PredictTheWinner(vector<int>& nums) {
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            sum[i] = nums[i] + sum[i - 1];
        }
        memset(mem, -1, sizeof(mem));
        int total = sum[nums.size() - 1];
        int score = dp(0, nums.size() - 1, nums);
        return score >= total - score;
    }

    int dp(int l, int r, vector<int>& nums) {
        if(l > r) return 0;

        int& ret = mem[l][r];
        if(~ret) return ret;
        
        return ret = max(
            nums[l] + getSum(l + 1, r) - dp(l + 1, r, nums),
            nums[r] + getSum(l, r - 1) - dp(l, r - 1, nums)
        );
    }
    
    int getSum(int l, int r) {
        if(l > r) return 0;
        return sum[r] - (l? sum[l - 1] : 0);
    }
};
