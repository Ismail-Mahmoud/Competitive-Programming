#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e5 + 9, OO = 0x3f3f3f3f;

int n, q, mark[N<<2];
lld A[N], w, h, tr[N<<2];

void push(int p){
    if(!mark[p]) return;
    tr[p*2] = tr[p*2+1] = tr[p];
    mark[p*2] = mark[p*2+1] = 1;
    mark[p] = 0;
}

lld build(int l = 0, int r = n-1, int p = 1){
    if(l == r) return tr[p] = A[l];
    int m = (l + r) >> 1;
    lld L = build(l, m, p*2);
    lld R = build(m+1, r, p*2+1);
    return tr[p] = max(L, R);
}

lld update(int l, int r, int ql, int qr, lld val, int p = 1){
    if(ql > r || qr < l) return tr[p];
    if(l >= ql && r <= qr){
        mark[p] = 1;
        return tr[p] = val;
    }
    push(p);
    int m = (l + r) >> 1;
    lld L = update(l, m, ql, qr, val, p*2);
    lld R = update(m+1, r, ql, qr, val, p*2+1);
    return tr[p] = max(L, R);
}

lld query(int l, int r, int ql, int qr, int p = 1){
    if(ql > r || qr < l) return -OO;
    if(l >= ql && r <= qr) return tr[p];
    push(p);
    int m = (l + r) >> 1;
    lld L = query(l, m, ql, qr, p*2);
    lld R = query(m+1, r, ql, qr, p*2+1);
    return max(L, R);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", A+i);
    build();
    scanf("%d", &q);
    while(q--){
        scanf("%lld %lld", &w, &h);
        lld mx = query(0, n-1, 0, w-1);
        printf("%lld\n", mx);
        update(0, n-1, 0, w-1, mx+h);
    }
    return 0;
}
