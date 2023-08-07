// https://leetcode.com/problems/number-of-music-playlists/

class Solution {
    int mem[101][101];
    static const int MOD = 1e9 + 7;
    int fact[101];
public:
    int numMusicPlaylists(int n, int goal, int k) {
        fact[0] = 1;
        for(int i = 1; i <= n; ++i) {
            fact[i] = 1LL * i * fact[i - 1] % MOD;
        }
        memset(mem, -1, sizeof(mem));
        return dp(goal, n, k) % MOD;
    }

    /*
    * dp[len][n] -> number of valid sequences with length (len) and (n) distinct numbers
    * dp[len][n] = dp[len-1][n] * (n-k)     // seq[len] can be any number other than the previous (k) numbers => multiply by (n-k)
                 + dp[len-1][n-1] * n       // if some number (x) didn't occur previously in the sequence, seq[len] must be this number
                                            // this is true for any of the (n) numbers => multiply by (n)
    * dp[len][0] = dp[len][len+c] = 0, where c > 0
    * dp[n][n] = n!
    * dp[k+1][n] = 0 if n != k+1
    */
    int dp(int len, int n, const int k) {
        if(!n || n > len) return 0;
        if(n == len) return fact[n];
        if(len == k + 1) return 0;  // n != len
        
        int& ret = mem[len][n];
        if(~ret) return ret;

        ret = 1LL * (n - k) * dp(len - 1, n, k) % MOD;
        ret += 1LL * n * dp(len - 1, n - 1, k) % MOD;

        return ret %= MOD;
    }
};
