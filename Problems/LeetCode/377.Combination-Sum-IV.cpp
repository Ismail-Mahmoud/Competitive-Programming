// https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for(int t = 1; t <= target; ++t) {
            for(int x : nums) {
                if(t - x >= 0) {
                    dp[t] += dp[t - x];
                }
            }
        }
        return dp[target];
    }
};
