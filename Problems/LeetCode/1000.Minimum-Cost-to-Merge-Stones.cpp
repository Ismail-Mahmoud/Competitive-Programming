class Solution {
    int n, original_k, OO = 1e7, sum[31];
    int mem[31][31][31];
    
    bool valid(int n, int k) {
        return k <= 2 || n % (k - 1) == 1;
    }
    
    // k => how many values will be combined (1 === original_k)
    int dp(int l, int r, int k) {
        k = k == 1? original_k : k;
        
        if(k == original_k && !valid(r - l + 1, k)) {
            return OO;
        }
        if(r - l + 1 < k) {
            return 0;
        }
        
        int& ret = mem[l][r][k];
        if(~ret) return ret;
        
        ret = OO;
        for(int i = l; i < r; ++i) {
            for(int s = 1; s < k; ++s) {
                ret = min(ret, dp(l, i, s) + dp(i + 1, r, k - s));
            }
        }
        
        return ret += (sum[r] - sum[l - 1]) * (k == original_k);
    }
public:
    int mergeStones(vector<int>& stones, int K) {
        n = stones.size(), original_k = K;
        
        if(n == 1) {
            return 0;
        }
        if(!valid(n, K)) {
            return -1;
        }
        
        stones.insert(stones.begin(), 0);
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            sum[i] = stones[i] + sum[i - 1];
        }
        
        memset(mem, -1, sizeof(mem));
        
        int ans = dp(1, n, 1);
        if(ans == OO) {
            ans = -1;
        }
        
        return ans;
    }
};