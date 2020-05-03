int pre[2005];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        int n = a.size(), m = b.size(), OO = 1000000000;
        vector<vector<int>> dp(n+1, vector<int>(m+1, OO));
        for(int j = 0; j < m; ++j)
            dp[0][j] = 1;
        dp[0][m] = 0;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= m; ++j){
                int id = 0;
                if(j == m) iota(pre, pre+m+1, 0), id = m+1;
                else{
                    pre[id++] = m;
                    if(j) pre[id++] = j-1;
                }
                int en = (j == m? a[i] : b[j]);
                for(int k = 0; k < id; ++k){
                    int p = pre[k];
                    int last = (p == m? a[i-1] : b[p]);
                    if(en > last)
                        dp[i][j] = min(dp[i][j], dp[i-1][p] + (j < m));
                }

            }
        }
        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());
        if(ans == OO) ans = -1;
        return ans;
    }
};
