#include <bits/stdc++.h>

const long long mod = 1000000007;

long long solve(long long m) {
    long long x = (m / 2);
    bool parity = x & 1;
    x = (x + 2) / 2;
    x %= mod;
    return (x * (x + 1) - x * !parity) % mod;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        long long m;
        scanf("%lld", &m);
        printf("%lld\n", solve(m));
    }
    return 0;
}