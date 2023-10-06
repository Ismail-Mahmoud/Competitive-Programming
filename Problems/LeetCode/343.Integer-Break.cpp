// https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int ans = 0;
        for(int c = 2; c <= (n >> 1); ++c) {
            ans = max(ans, calc(n, c));
        }
        return ans;
    }
    int calc(int n, int c) {
        int q = n / c, r = n % c, ret = 1;
        while(c--) {
            ret *= q + (r-- > 0);
        }
        return ret;
    }
};
