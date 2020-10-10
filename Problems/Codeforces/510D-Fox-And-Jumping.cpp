#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int n, L[300], C[300], M[300], mem[300][1 << 9];
vector<int> factors;

void factorize(int x) {
    factors.clear();
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) {
            factors.push_back(i);
            do {
                x /= i;
            } while(x % i == 0);
        }
    }
    if(x > 1) {
        factors.push_back(x);
    }
}

void generateMasks() {
    for(int i = 0; i < n; ++i) {
        M[i] = 0;
        for(int f = 0; f < factors.size(); ++f) {
            if(L[i] % factors[f] == 0) {
                M[i] |= 1 << f;
            }
        }
    }
}

int dp(int i, int mask) {
    if(i == n) return !mask? 0 : OO;

    int& ret = mem[i][mask];
    if(~ret) return ret;

    ret = dp(i + 1, mask);
    ret = min(ret, C[i] +  dp(i + 1, mask & M[i]));

    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", L + i);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", C + i);
    }
    int ans = OO;
    for(int i = 0; i < n; ++i) {
        factorize(L[i]);
        generateMasks();
        memset(mem, -1, sizeof(mem));
        ans = min(ans, C[i] + dp(0, (1 << factors.size()) - 1));
    }
    printf("%d\n", ans == OO? -1 : ans);
    return 0;
}