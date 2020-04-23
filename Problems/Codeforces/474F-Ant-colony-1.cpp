#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MIN     first
#define GCD     second
#define all(v)  v.begin(), v.end()
#define mk      make_pair

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 9, OO = 0x3f3f3f3f;

int n, A[N];
vector<pii> f;
pii tr[N<<2];

pii build(int l, int r, int p){
    if(l == r) return tr[p] = mk(A[l], A[l]);

    int m = (l + r) >> 1;
    pii L = build(l, m, p*2);
    pii R = build(m+1, r, p*2+1);

    return tr[p] = mk(min(L.MIN, R.MIN), __gcd(L.GCD, R.GCD));
}

pii get(int l, int r, int ql, int qr, int p){
    if(qr < l || ql > r) return mk(OO, 0);
    if(l >= ql && r <= qr) return tr[p];

    int m = (l + r) >> 1;
    pii L = get(l, m, ql, qr, p*2);
    pii R = get(m+1, r, ql, qr, p*2+1);

    return mk(min(L.MIN, R.MIN), __gcd(L.GCD, R.GCD));
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", A + i);
        f.push_back(mk(A[i], i));
    }
    sort(all(f));
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = r - l + 1;
        pii p = get(1, n, l, r, 1);
        if(p.MIN == p.GCD){
            int cnt = upper_bound(all(f), mk(p.MIN, r)) - lower_bound(all(f), mk(p.MIN, l));
            ans -= cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
