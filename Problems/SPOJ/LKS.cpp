#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 9;

int n, W, dp[N], val[N], wt[N];

void solve(){
    for(int j = W; j >= wt[0]; --j)
        dp[j] = val[0];

    for(int i = 1; i < n; ++i)
        for(int j = W; j >= wt[i]; --j)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);

    printf("%d\n", dp[W]);
}

int main()
{
    scanf("%d %d", &W, &n);
    for(int i = 0; i < n; ++i)
        scanf("%d %d", val + i, wt + i);
    solve();
    return 0;
}
