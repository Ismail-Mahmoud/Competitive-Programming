class Solution {
    int mem[12][10001];
    static const int OO = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(mem, -1, sizeof(mem));
        int ans = dp(0, amount, coins);
        if(ans >= OO) ans = -1;
        return ans;
    }

    int dp(int i, int rem, const vector<int>& coins) {
        if(!rem) return 0;
        if(i == coins.size()) return OO;

        int& ret = mem[i][rem];
        if(~ret) return ret;

        ret = dp(i + 1, rem, coins);
        if(coins[i] <= rem) {
            ret = min(ret, 1 + dp(i, rem - coins[i], coins));
        }

        return ret;
    }
};

class Solution {
    int dp[13][10001];
    static const int OO = 0x3f3f3f3f;
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, OO, sizeof(dp));
        for(int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 0;
        }
        for(int i = coins.size() - 1; ~i; --i) {
            for(int rem = 1; rem <= amount; ++rem) {
                dp[i][rem] = dp[i + 1][rem];
                if(coins[i] <= rem) {
                    dp[i][rem] = min(dp[i][rem], 1 + dp[i][rem - coins[i]]);
                }
            }
        }
        return dp[0][amount] >= OO? -1 : dp[0][amount];
    }
};

class Solution {
    int dp[10001];
    static const int OO = 0x3f3f3f3f;
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, OO, sizeof(dp));
        dp[0] = 0;
        for(int i = coins.size() - 1; ~i; --i) {
            for(int rem = 1; rem <= amount; ++rem) {
                if(coins[i] <= rem) {
                    dp[rem] = min(dp[rem], 1 + dp[rem - coins[i]]);
                }
            }
        }
        return dp[amount] >= OO? -1 : dp[amount];
    }
};
