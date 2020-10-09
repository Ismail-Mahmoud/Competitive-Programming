#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e5 + 5, K = 17, MOD = 1000000007;

int n, a[N], T[N][K], lg[N];
set<int> b[N];

void build() {
    lg[0] = -1;
    for(int i = 0; i < n; ++i) {
        T[i][0] = a[i];
        lg[i+1] = lg[i] + !(i & (i + 1));
    }
    for(int k = 1; (1<<k) <= n; ++k) {
        for(int i = 0; i+(1<<k) <= n; ++i) {
            T[i][k] = T[i][k-1] | T[i+(1<<k-1)][k-1];
        }
    }
}

int OR(int l, int r) {
    int k = lg[r-l+1];
    return T[l][k] | T[r-(1<<k)+1][k];
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
        for(int k = 0; k < 31; ++k) b[k].clear();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            for(int k = 0; k < 31; ++k) {
                if((a[i] >> k) & 1) b[k].insert(i);
            }
        }
        build();
        set<int> res;
        for(int i = 0; i < n; ++i) {
            res.insert(a[i]);
            for(int k = 0; k < 31; ++k) {
                if((a[i] >> k) & 1) continue;
                auto it = b[k].upper_bound(i);
                if(it == b[k].end()) continue;
                res.insert(OR(i, *it));
            }
        }
        printf("%d\n", res.size());
    }
    return 0;
}