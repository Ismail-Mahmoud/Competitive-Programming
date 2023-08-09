// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums[0], mid;
        while(lo < hi) {
            mid = (lo + hi) >> 1;
            if(check(mid, nums, p)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    bool check(int max_diff, const vector<int>& nums, int pairs) {
        for(int i = 1; i < nums.size() && pairs; ++i) {
            if(abs(nums[i] - nums[i - 1]) <= max_diff) {
                --pairs;
                ++i;
            }
        }
        return !pairs;
    }
};
