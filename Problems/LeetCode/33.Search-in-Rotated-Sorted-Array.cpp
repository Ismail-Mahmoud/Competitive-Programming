// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while(l <= r) {
            m = (l + r) >> 1;
            if(target == nums[m]) {
                return m;
            }
            if(nums[m] >= nums[l]) {
                if(in_range(target, nums, l, m)) r = m - 1;
                else l = m + 1;
            }
            else {
                if(in_range(target, nums, m, r)) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }

    bool in_range(int target, vector<int>& nums, int l, int r) {
        return target >= nums[l] && target <= nums[r];
    }
};
