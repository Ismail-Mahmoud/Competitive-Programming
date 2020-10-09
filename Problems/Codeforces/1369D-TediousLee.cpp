#include <bits/stdc++.h>

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'


using namespace std;

typedef long long lld;

const int N = 2e6 + 5, K = 17, MOD = 1000000007;

int n;
lld mem[N][3];

lld dp(int i, int val) {
    if(i == 4) return 1;
    if(i == 3) return val;
    if(i == 1 || i == 2) return 0;
//if(i < 100) DBG2(i, val);
    lld& ret = mem[i][val];
    if(~ret) return ret;

    // Leave this, valid to take next
    ret = 2 * dp(i - 2, 1) + dp(i - 1, 1);

    // valid to take this, invalidate next
    if(val) {
        ret = max(ret, (2 * dp(i - 2, 0) + dp(i - 1, 0)) + 1);
    }

    ret %= MOD;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    memset(mem, -1, N * sizeof mem[0]);
    dp(2000000, 1);
    while(t--) {
        scanf("%d", &n);
        lld ans = (dp(n, 1) * 4) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}