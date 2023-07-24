// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> next_greater(nums.size(), -1), stk;
        for(int i = 0; i < nums.size(); ++i) {
            while(!stk.empty() && nums[i] > nums[stk.back()]) {
                next_greater[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }

        vector<int> prev_less(nums.size(), -1); stk.clear();
        for(int i = nums.size() - 1; ~i; --i) {
            while(!stk.empty() && nums[i] < nums[stk.back()]) {
                prev_less[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(~prev_less[i] && ~next_greater[i]) {
                return true;
            }
        }
        return false;
    }
};