#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e5 + 5, K = 17, MOD = 1000000007;

int n, a[N], next_1[32][N];

int OR(int l, int r) {
    int ret = 0;
    for(int k = 0; k < 31;++k) {
        if(next_1[k][l] > r) continue;
        ret |= (1<<k);
    }
    return ret;
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
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }
        a[n] = INT_MAX;
        for(int k = 0; k < 31; ++k) {
            memset(next_1[k], 0, (n + 1) * sizeof(next_1[k][0]));
            for(int i = n; ~i; --i) if(a[i] & (1<<k)) {
                int tmp = i;
                for(--i; ~i && !(a[i] & (1<<k)); --i) {
                    next_1[k][i] = tmp;
                }
                ++i;
            }
        }
        set<int> res;
        for(int i = 0; i < n; ++i) {
            res.insert(a[i]);
            for(int k = 0; k < 31; ++k) {
                if(a[i] & (1<<k)) continue;
                int idx = next_1[k][i];
                if(idx == n) continue;
                res.insert(OR(i, idx));
            }
        }
        printf("%d\n", res.size());
    }
    return 0;
}