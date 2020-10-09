#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e5 + 5, M = 1e6, K = 20;

int n, sz[N];
vector<int> G[N], C;

void dfs(int u, int p) {
    sz[u] = 1;
    bool cent = true;
    for(int v : G[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > n / 2) cent = false;
    }
    if(n - sz[u] > n / 2) cent = false;
    if(cent) C.push_back(u);
}

pair<int, int> dfs2(int u, int p) {
    if(G[u].size() == 1) return {u, p};
    for(int v : G[u]) {
        if(v == p) continue;
        return dfs2(v, u);
    }
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
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i) {
            G[i].clear();
        }
        C.clear();
        for(int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, 0);
        pair<int, int> cut, add;
        if(C.size() == 1) {
            cut = {C[0], G[C[0]][0]};
            add = {C[0], G[C[0]][0]};
        }
        else {
            cut = dfs2(C[1], C[0]); // single node at subtree of C[1] & its parent
            add = {C[0], cut.first};
        }
        printf("%d %d\n", cut.first, cut.second);
        printf("%d %d\n", add.first, add.second);
    }
    return 0;
}