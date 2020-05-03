class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        if(!n) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int l = n-1; ~l; --l)
        for(int r = l; r < n; ++r)
        for(int i = l; i <= r; ++i)
            dp[l][r] = max(dp[l][r], a[i] * (l? a[l-1] : 1) * (r<n-1? a[r+1] : 1)
                                   + (l<=i-1? dp[l][i-1] : 0)
                                   + (i+1<=r? dp[i+1][r] : 0));
        return dp[0][n-1];
    }
};
