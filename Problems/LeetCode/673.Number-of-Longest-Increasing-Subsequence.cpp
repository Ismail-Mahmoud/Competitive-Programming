// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
    static const int N = 2000;
    pair<int, int> dp[N];
public:
    int findNumberOfLIS(vector<int>& nums) {
        int max_lis = 1;
        for(int i = 0; i < nums.size(); ++i) {
            dp[i] = {1, 1};
        }
        for(int j = 0; j < nums.size(); ++j) {
            for(int i = 0; i < j; ++i) {
                if(nums[i] >= nums[j]) continue;
                int cur_lis = dp[j].first;
                int new_lis = dp[i].first + 1;
                int new_cnt = dp[i].second;
                if(new_lis > cur_lis) {
                    dp[j] = {new_lis, new_cnt};
                    max_lis = max(max_lis, new_lis);
                }
                else if(new_lis == cur_lis) {
                    dp[j].second += new_cnt;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(dp[i].first == max_lis) {
                ans += dp[i].second;
            }
        }
        return ans;
    }
};