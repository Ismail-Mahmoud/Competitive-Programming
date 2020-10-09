#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 2e5 + 5;

int n, k, x[N], cnt[N], mem[N][3];

int dp(int i, int p) {
    if(i >= n || p == 2) return 0;

    int& ret = mem[i][p];
    if(~ret) return ret;

    return ret = max(dp(i + 1, p), cnt[i] + dp(i + cnt[i], p + 1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", x + i);
        }
        for(int i = 0; i < n; ++i) {
            int y;
            scanf("%d", &y);
        }
        sort(x, x + n);
        for(int i = 0; i < n; ++i) {
            cnt[i] = upper_bound(x, x + n, x[i] + k) - (x + i);
        }
        memset(mem, -1, n * sizeof(mem[0]));
        printf("%d\n", dp(0, 0));
    }
    return 0;
}