#include <bits/stdc++.h>

#define ff      first
#define ss      second
#define mkp(a,b)make_pair(a,b)
#define all(v)  v.begin(), v.end()

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;
typedef vector<int> vii;

const int N = 3e4 + 4;

int n, m, a[N], nxt[N];
vii tr[N<<2], pos[1000006];

void build(int l, int r, int p){
    if(l == r) return tr[p] = {nxt[l]}, void();

    int m = (l + r) >> 1;
    build(l, m, p*2);
    build(m+1, r, p*2+1);

    merge(all(tr[p*2]), all(tr[p*2+1]), back_inserter(tr[p]));
}

int get(int l, int r, int ql, int qr, int k, int p){
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return tr[p].end() - upper_bound(all(tr[p]), k);

    int m = (l + r) >> 1;
    int L = get(l, m, ql, qr, k, p*2);
    int R = get(m+1, r, ql, qr, k, p*2+1);

    return L + R;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        pos[a[i]].push_back(i);
    }
    for(int i = 1; i <= 1000000; ++i){
        if(pos[i].empty()) continue;
        for(int j = 0; j < (int)pos[i].size()-1; ++j)
            nxt[pos[i][j]] = pos[i][j+1];
        nxt[pos[i].back()] = n+1;
    }
    build(1, n, 1);
    scanf("%d", &m);
    while(m--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", get(1, n, l, r, r, 1));
    }
    return 0;
}
