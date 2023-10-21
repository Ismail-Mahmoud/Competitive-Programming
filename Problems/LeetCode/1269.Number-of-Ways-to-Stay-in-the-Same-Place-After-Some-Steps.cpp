// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

class Solution {
    static const int MOD = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps / 2 + 1);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int s = 1; s <= steps; ++s) {
            vector<int> tmp = dp;
            for(int i = 0; i < n; ++i) {
                if(i) dp[i] = (dp[i] + tmp[i - 1]) % MOD;
                if(i < n - 1) dp[i] = (dp[i] + tmp[i + 1]) % MOD;
            }
        }
        return dp[0];
    }
};
