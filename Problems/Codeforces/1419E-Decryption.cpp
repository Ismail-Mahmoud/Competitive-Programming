#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> f, ans;
map<int, bool> vis;

void add(int x) {
    if(!vis[x]) {
        ans.push_back(x);
        vis[x] = true;
    }
}

void init() {
    int a = f[0], b = f[1], c = f[2];
    add(a);
    add(a * b);
    add(b);
    add(b * c);
    add(c);
    add(a * c);
    add(a * b * c);
}

void go(int x) {
    int sz = ans.size();
    for(int i = 0; i < sz; ++i) {
        if(i) add(x);
        add(x * ans[i]);
    }
}

void factorize() {
    int tmp = n;
    for(int i = 2; i <= n / i; ++i) {
        while(tmp % i == 0) {
            f.push_back(i);
            tmp /= i;
        }
    }
    if(tmp > 1) f.push_back(tmp);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        f.clear(); ans.clear(); vis.clear();
        scanf("%d", &n);
        factorize();
        if(f.size() == 2) {
            if(f[0] == f[1]) printf("%d %d\n%d\n", f[0], n, 0);
            else printf("%d %d %d\n%d\n", f[0], f[1], n, 1);
            continue;
        }
        init();
        for(int i = 3; i < f.size(); ++i) {
            go(f[i]);
        }
        for(int x : ans) {
            printf("%d ", x);
        }
        puts("\n0");
    }
    return 0;
}