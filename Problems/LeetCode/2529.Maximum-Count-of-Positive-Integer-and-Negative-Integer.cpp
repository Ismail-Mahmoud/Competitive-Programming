// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int first_non_neg_idx = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int neg = first_non_neg_idx;

        int first_pos_idx = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = n - first_pos_idx;

        return max(neg, pos);
    }
};