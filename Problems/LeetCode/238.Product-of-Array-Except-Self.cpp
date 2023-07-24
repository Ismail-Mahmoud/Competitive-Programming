// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeros = 0;
        for(int x : nums) {
            if(!x) ++zeros;
            else product *= x;
        }
        if(zeros > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for(int x : nums) {
            if(!x) ans.push_back(product);
            else ans.push_back(product * !zeros / x);
        }
        return ans;
    }
};