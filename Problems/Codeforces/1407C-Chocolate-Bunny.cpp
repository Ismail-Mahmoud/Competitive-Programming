#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e4 + 5, M = 1e6, K = 20;

int n, p[N], f[N];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    int x = 1, y = 2;
    for( ; y <= n; ++y) {
        // x = q * y + r1
        cout << "? " << x << ' ' << y << '\n';
        cout.flush();
        int r1; cin >> r1;
        if(r1 == -1) return 0;

        // y = q * x + r2
        cout << "? " << y << ' ' << x << '\n';
        cout.flush();
        int r2; cin >> r2;
        if(r2 == -1) return 0;

        if(r1 < r2) {
            p[y] = r2;
            f[r2] = 1;
        }
        else {
            p[x] = r1;
            f[r1] = 1;
            x = y;
        }
    }
    p[x] = n;
    cout << '!';
    for(int i = 1; i <= n; ++i) {
        cout << ' ' << p[i];
    }
    return 0;
}