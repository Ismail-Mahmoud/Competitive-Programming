#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 20;

int n, k, a[N], T[N][K], lg[N];
map<int, long long> ans;

int get(int l, int r) {
    int k = lg[r-l+1];
    return __gcd(T[l][k], T[r-(1<<k)+1][k]);
}

void build() {
    lg[0] = -1;
    lg[1] = 0;
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i>>1] + 1;

    for(int i = 0; i < n; ++i)
        T[i][0] = a[i];

    for(int k = 1; (1<<k) <= n; ++k)
        for(int i = 0; i+(1<<k) <= n; ++i)
            T[i][k] = __gcd(T[i][k-1], T[i+(1<<k-1)][k-1]);

    for(int i = 0; i < n; ++i) {
        int g = a[i], pos = i;
        while(pos < n) {
            int l = pos, r = n - 1, m;
            while(l < r) {
                m = (l + r + 1) >> 1;
                if(get(i, m) == g) l = m;
                else r = m - 1;
            }
            ans[g] += r - pos + 1;
            pos = r + 1;
            //cout<<g<<" "<<pos<<endl;
            g = get(i, pos);
        }
        cout<<endl;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", a + i);
    build();
    scanf("%d", &k);
    while(k--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}