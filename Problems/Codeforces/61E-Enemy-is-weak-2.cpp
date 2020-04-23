#include <bits/stdc++.h>

#define all(v)  v.begin(), v.end()

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

using namespace std;

typedef long long lld;

const int N = 1e6 + 3;

int n, a[N];
vector<int> tr[N<<2];

void build(int l, int r, int p){
    if(l == r){
        tr[p] = {a[l]};
        return;
    }

    int m = (l + r) >> 1;
    build(l, m, p*2);
    build(m+1, r, p*2+1);

    merge(all(tr[p*2]), all(tr[p*2+1]), back_inserter(tr[p]));
}

int get(int l, int r, int ql, int qr, int val, int w, int p){
    if(l > r || l > qr || r < ql) return 0;
    if(l >= ql && r <= qr){
        if(w) return tr[p].end() - upper_bound(all(tr[p]), val);
        else return upper_bound(all(tr[p]), val) - tr[p].begin();
    }

    int m = (l + r) >> 1;
    int L = get(l, m, ql, qr, val, w, p*2);
    int R = get(m+1, r, ql, qr, val, w, p*2+1);

    return L + R;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    build(0, n-1, 1);
    lld ans = 0;
    for(int i = 0; i < n; ++i){
        int L = get(0, n-1, 0, i-1, a[i], 1, 1);
        int R = get(0, n-1, i+1, n-1, a[i], 0, 1);
        //DBG2(L, R);
        ans += 1LL * L * R;
    }
    printf("%lld\n", ans);
    return 0;
}
