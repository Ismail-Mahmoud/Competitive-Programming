#include <bits/stdc++.h>

#define ff      first
#define ss      second
#define mkp(a,b)make_pair(a,b)

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

const int N = 6e4 + 4;

int t, n, k, a[N], tr[N<<2];

int build(int l, int r, int p){
    if(l == r) return tr[p] = a[l];

    int m = (l + r) >> 1;
    int L = build(l, m, p*2);
    int R = build(m+1, r, p*2+1);

    return tr[p] = L & R;
}

int get(int l, int r, int ql, int qr, int p){
    if(l > qr || r < ql) return -1;
    if(l >= ql && r <= qr) return tr[p];

    int m = (l + r) >> 1;
    int L = get(l, m, ql, qr, p*2);
    int R = get(m+1, r, ql, qr, p*2+1);

    return L & R;
}

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        copy(a, a + n, a + n);
        copy(a, a + n, a + 2*n);
        //DBGARR(a,3*n,int);
        k = min(k, n/2);
        build(0, 3*n-1, 1);
        for(int i = n; i < 2*n; ++i){
            int l = i - k, r = i + k;
            //DBG2(l, r);
            printf("%d%c", get(0, 3*n-1, l, r, 1), " \n"[i == 2*n-1]);
        }
    }
    return 0;
}
