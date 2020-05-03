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

const int N = 2e6 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f;

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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        map<int, int> mp;
        for(int i = 0; i < n; ++i){
            int x;
            scanf("%d", &x);
            mp[-x] = i;
        }
        lld ans = 0;
        BIT bit(n);
        while(!mp.empty()){
            int i = mp.begin()->ss;
            ans += bit.get(i);
            bit.add(i, 1);
            mp.erase(mp.begin());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
