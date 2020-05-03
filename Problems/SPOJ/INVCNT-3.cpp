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
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<lld> vll;
typedef pair<lld, lld> pll;
typedef vector<pair<lld, lld>> vpll;

const int N = 2e5 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f;

int n, a[N];

struct BIT{
    vector<int> a;
    BIT(int n){
        a.resize(n);
    }
    void add(int i, int v){
        for(++i; i <= a.size(); i += i & -i)
            a[i-1] += v;
    }
    int get(int i){
        int ret = 0;
        for(++i; i; i -= i & -i)
            ret += a[i-1];
        return ret;
    }
};

void compress(){
    int* tmp = new int[n];
    copy(a, a + n, tmp);
    sort(tmp, tmp + n);
    // int new_size = unique(tmp, tmp + n) - tmp; // if elements are not distinct
    for(int i = 0; i < n; ++i)
        a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;
    delete []tmp;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", a + i);
        }
        compress();
        lld ans = 0;
        BIT bit(n);
        for(int i = n - 1; ~i; --i){
            ans += bit.get(a[i] - 1);
            bit.add(a[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
