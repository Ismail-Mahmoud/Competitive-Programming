class Solution {
    int mem[300][5001];
public:
    int change(int amount, vector<int>& coins) {
        memset(mem, -1, sizeof(mem));
        return dp(0, amount, coins);
    }
    int dp(int i, int rem, const vector<int>& coins) {
        if(!rem) return 1;
        if(rem < 0 || i == coins.size()) return 0;
        
        int& ret = mem[i][rem];
        if(~ret) return ret;

        return ret = dp(i + 1, rem, coins) + dp(i, rem - coins[i], coins);
    }
};

class Solution {
    int dp[301][5001];
public:
    int change(int amount, vector<int>& coins) {
        for(int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }
        for(int i = coins.size() - 1; ~i; --i) {
            for(int rem = 1; rem <= amount; ++rem) {
                dp[i][rem] = dp[i + 1][rem];
                if(coins[i] <= rem) {
                    dp[i][rem] += dp[i][rem - coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};

class Solution {
    int dp[5001];
public:
    int change(int amount, vector<int>& coins) {
        dp[0] = 1;
        for(int i = coins.size() - 1; ~i; --i) {
            for(int rem = 1; rem <= amount; ++rem) {
                if(coins[i] <= rem) {
                    dp[rem] += dp[rem - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};
