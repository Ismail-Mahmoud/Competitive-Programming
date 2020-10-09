#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e5 + 5;

int n, a, b, da, db, dist, diam;
vector<int> G[N];

int dfs(int u, int p, int d) {
    if(u == b) dist = d;
    int max_dep[3] = {0, 0, 0};
    for(int v : G[u]) {
        if(v == p) continue;
        max_dep[0] = 1 + dfs(v, u, d + 1);
        sort(max_dep, max_dep + 3);
    }
    diam = max(diam, max_dep[1] + max_dep[2]);
    return max_dep[2];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        dist = diam = 0;
        scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
        --a, --b;
        for(int i = 0; i < n; ++i) {
            G[i].clear();
        }
        for(int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(a, -1, 0);
        //cout<<dist<<" "<<diam<<endl;
        db = min(db, diam);
        if((da * 2 >= db) || (dist <= da)) {
            puts("Alice");
        }
        else {
            puts("Bob");
        }
    }
    return 0;
}