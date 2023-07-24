// https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int max_sum = sum;
        for(int i = k; i < nums.size(); ++i) {
            max_sum = max(max_sum, sum += nums[i] - nums[i - k]);
        }
        return 1.0 * max_sum / k;
    }
};