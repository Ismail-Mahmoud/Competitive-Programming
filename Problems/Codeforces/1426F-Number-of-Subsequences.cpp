#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, MOD = 1000000007;

int n, a[N], b[N], c[N], q[N], p3[N], numq;
long long ans;
char s[N];

inline int sum(int l, int r, int* arr) {
    return arr[r] - arr[l - 1];
}

inline long long mul(long long x, long long y) {
    return x * y % MOD;
}

inline void add(long long& x, long long y) {
    x += y;
    x -= MOD * (x >= MOD);
}

inline long long calc(int i) {
    numq -= s[i] == '?';

    // absolute As * absolute Cs
    long long ret = mul(mul(sum(1, i - 1, a), sum(i + 1, n, c)), p3[numq]);
    // possible As * absolute Cs
    if(numq >= 1) {
        add(ret, mul(mul(sum(1, i - 1, q), sum(i + 1, n, c)), p3[numq - 1]));
    }
    // absolute As * possible Cs
    if(numq >= 1) {
        add(ret, mul(mul(sum(1, i - 1, a), sum(i + 1, n, q)), p3[numq - 1]));
    }
    // possible As * possible Cs
    if(numq >= 2){
        add(ret, mul(mul(sum(1, i - 1, q), sum(i + 1, n, q)), p3[numq - 2]));
    }

    numq += s[i] == '?';

    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    p3[0] = 1;
    for(int i = 1; i < N; ++i) {
        p3[i] = mul(p3[i - 1], 3);
    }
    scanf("%d %s", &n, s + 1);
    for(int i = 1; s[i]; ++i) {
        a[i] = a[i - 1] + (s[i] == 'a');
        b[i] = b[i - 1] + (s[i] == 'b');
        c[i] = c[i - 1] + (s[i] == 'c');
        q[i] = q[i - 1] + (s[i] == '?');
    }
    numq = q[n];
    for(int i = 2; i < n; ++i) {
        if(s[i] == 'b' || s[i] == '?') {
            add(ans, calc(i));
        }
    }
    printf("%lld\n", ans);
    return 0;
}