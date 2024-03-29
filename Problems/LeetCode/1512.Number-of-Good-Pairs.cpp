// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(101, 0);
        for(int x : nums) {
            ans += freq[x]++;
        }
        return ans;
    }
};
