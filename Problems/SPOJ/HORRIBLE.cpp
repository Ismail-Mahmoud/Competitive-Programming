#include <bits/stdc++.h>

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

#define ff  first
#define ss  second
#define mkp make_pair

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

const int N = 1e3 + 3, LG = 10;

struct BIT{
    vector<lld> a, b;
    BIT(int n){
        a.resize(n);
        b.resize(n);
    }
    void add(int i, lld va, lld vb){
        for(++i; i < a.size(); i += i & -i)
            a[i] += va, b[i] += vb;
    }
    lld get(int i){
        lld ret = 0; int ii = i;
        for(++i; i; i -= i & -i)
            ret += a[i] * ii + b[i];
        return ret;
    }
    void addRng(lld l, lld r, lld v){
        add(l, v, -v*(l-1));
        add(r, -v, v*r);
    }
    lld getRng(int l, int r){
        return get(r) - get(l-1);
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        BIT bit(n+3);
        while(q--){
            int w, l, r, v;
            scanf("%d %d %d", &w, &l, &r);
            if(w) printf("%lld\n", bit.getRng(l, r));
            else bit.addRng(l, r, scanf("%d", &v) * v);
        }
    }
    return 0;
}
