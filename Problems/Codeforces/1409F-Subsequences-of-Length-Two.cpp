#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 2e5 + 5;

int n, k, mem[202][202][202];
char s[202], t[3];

int dp(int i, int c0, int k) {
    if(i == n) return 0;

    int& ret = mem[i][c0][k];
    if(~ret) return ret;

    if(s[i] == t[0]) {
        // don't change
        ret = dp(i + 1, c0 + 1, k);
        // change to t[1]
        if(k) ret = max(ret, c0 + dp(i + 1, c0, k - 1));
    }
    else if(s[i] == t[1]) {
        // don't change
        ret = c0 + dp(i + 1, c0, k);
        // change to t[0]
        if(k) ret = max(ret, dp(i + 1, c0 + 1, k - 1));
    }
    else {
        // don't change
        ret = dp(i + 1, c0, k);
        // change to t[0]
        if(k) ret = max(ret, dp(i + 1, c0 + 1, k - 1));
        // change to t[1]
        if(k) ret = max(ret, c0 + dp(i + 1, c0, k - 1));
    }

    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &k);
    scanf("%s %s", s, t);
    memset(mem, -1, n * sizeof(mem[0]));
    int ans;
    if(t[0] == t[1]) {
        int c = count(s, s + n, t[0]);
        c = min(n, c + k);
        ans = c * (c - 1) / 2;
    }
    else {
        ans = dp(0, 0, k);
    }
    printf("%d\n", ans);
    return 0;
}