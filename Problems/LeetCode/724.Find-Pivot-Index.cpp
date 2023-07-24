// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }
        for(int i = 0, sum = 0; i < nums.size(); ++i) {
            if(sum == total - sum - nums[i]) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};