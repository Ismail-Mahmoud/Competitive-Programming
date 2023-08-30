// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int last = nums.back();
        for(int i = nums.size() - 2; ~i; --i) {
            int cnt = (nums[i] + last - 1) / last;
            ans += cnt - 1;
            last = nums[i] / cnt;
        }
        return ans;
    }
};
