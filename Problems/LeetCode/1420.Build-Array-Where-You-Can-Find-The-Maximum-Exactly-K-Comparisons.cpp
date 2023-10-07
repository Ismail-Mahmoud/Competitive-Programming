// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

class Solution {
    static const int MOD = 1e9 + 7;
    int mem[51][101][51], M;
public:
    int numOfArrays(int n, int m, int k) {
        M = m;
        memset(mem, -1, sizeof(mem));
        return dp(n, 0, k);
    }
    
    int dp(int n, int mx, int k) {
        if(k < 0) return 0;
        if(!n) return !k;

        int& ret = mem[n][mx][k];
        if(~ret) return ret;

        ret = 0;
        for(int x = 1; x <= M; ++x) {
            ret += dp(n - 1, max(x, mx), k - (x > mx));
            ret %= MOD;
        }

        return ret;
    }
};
