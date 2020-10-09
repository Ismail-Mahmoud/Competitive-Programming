#include <bits/stdc++.h>

using namespace std;

const int N = 2005, M = N << 1;

int n, mat[N][N], id, L[N], idxOfNode[N], nodeOfIdx[M];
long long dist[N];
vector<pair<int, int>> G[N];

struct edge {
    int from, to, cost;
    edge(int f, int t, int c): from(f), to(t), cost(c) {}
};
vector<edge> E;

struct DSU {
    int par[N], sz[N];
    void init() {
        iota(par, par + n, 0);
        fill(sz, sz + n, 1);
    }
    int operator [](int u) {
        return par[u] = par[u] == u? u : (*this)[par[u]];
    }
    bool operator ()(int u, int v) {
        u = (*this)[u];
        v = (*this)[v];
        if(u == v) return true;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        sz[v] = 0;
        return false;
    }
} dsu;

struct ST {
    int T[M][13], lg[M];
    int mini(int u, int v) {
        return L[u] < L[v]? u : v;
    }
    void build() {
        lg[0]= -1;
        for(int i = 0; i < id; ++i) {
            lg[i+1] = lg[i] + !(i & (i + 1));
            T[i][0] = nodeOfIdx[i];
        }
        for(int k = 1; (1<<k) <= id; ++k) {
            for(int i = 0; i+(1<<k) <= id; ++i) {
                T[i][k] = mini(T[i][k-1], T[i+(1<<k-1)][k-1]);
            }
        }
    }
    int RMQ(int l, int r) {
        if(l > r) swap(l, r);
        int k = lg[r-l+1];
        return mini(T[l][k], T[r-(1<<k)+1][k]);
    }
} st;

void dfs(int u, int p) {
    idxOfNode[u] = id;
    nodeOfIdx[id++] = u;
    for(auto it : G[u]) {
        int v = it.first, c = it.second;
        if(v == p) continue;
        L[v] = L[u] + 1;
        dist[v] = dist[u] + c;
        dfs(v, u);
        nodeOfIdx[id++] = u;
    }
}

int LCA(int u, int v) {
    return st.RMQ(idxOfNode[u], idxOfNode[v]);
}

bool check(int u, int v) {
    if(u == v) return !mat[u][v] && !mat[v][u];
    int lca = LCA(u, v);
    long long d = dist[u] + dist[v] - (dist[lca] << 1);
    return d && d == mat[u][v] && d == mat[v][u];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", mat[i] + j);
            E.emplace_back(i, j, mat[i][j]);
        }
    }
    sort(E.begin(), E.end(), [](edge a, edge b) {
        return a.cost < b.cost;
    });
    dsu.init();
    for(edge e : E) {
        int u = e.from, v = e.to, c = e.cost;
        if(dsu(u, v)) continue;
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }
    L[0] = dist[0] = 0;
    dfs(0, -1);
    st.build();
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(check(i, j)) continue;
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}