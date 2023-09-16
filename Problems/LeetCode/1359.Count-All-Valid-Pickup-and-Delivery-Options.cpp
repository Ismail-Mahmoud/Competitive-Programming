// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        int ans = 1;
        while(n) {
            ans = 1LL * ans * n % MOD;
            ans = 1LL * ans * (2 * n - 1) % MOD;
            --n;
        }
        return ans;
    }
};
