// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        nums.insert(nums.end(), nums.begin(), nums.end());
        int N = n << 1;
        for(int l = 0, r = n; l <= n && r < N; ) {
            if(sum < x) sum += nums[r++];
            else if(sum > x) sum -= nums[l++];
            else {
                ans = min(ans, r - l);
                sum += nums[r++] - nums[l++];
            }
        }
        return ans > n? -1 : ans;
    }
};
