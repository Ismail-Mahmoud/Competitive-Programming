// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        for(int i = 1, pow2 = 1; i <= n; ++i) {
            if(i == pow2 << 1) {
                pow2 = i;
            }
            ans[i] = ans[i - pow2] + 1;
        }
        return ans;
    }
};
