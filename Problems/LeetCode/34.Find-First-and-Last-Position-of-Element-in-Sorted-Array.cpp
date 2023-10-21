// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {bs1(nums, target), bs2(nums, target)};
    }

    int bs1(const vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int lo = 0, hi = nums.size() - 1, mid;
        while(lo < hi) {
            mid = (lo + hi) >> 1;
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return nums[lo] == target? lo : -1;
    }

    int bs2(const vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int lo = 0, hi = nums.size() - 1, mid;
        while(lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if(nums[mid] > target) hi = mid - 1;
            else lo = mid;
        }
        return nums[lo] == target? lo : -1;
    }
};
