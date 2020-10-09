#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e3 + 5, K = 17, MOD = 1000000007;

int n, max_dep, root, dist;
vector<int> G[N], dep[N], all;

void dfs(int u, int p, int d) {
    max_dep = max(max_dep, d);
    dep[d].push_back(u);
    for(int v : G[u]) {
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
}

void dfs2(int u, int p, int d, vector<int>& vec) {
//    cout << u << " " << d<< endl;
    if(d == dist) {
        vec.push_back(u);
        return;
    }
    for(int v : G[u]) {
        if(v == p) continue;
        dfs2(v, u, d + 1, vec);
    }
}

pair<int, int> query(vector<int>& nodes) {
    cout << "? " << nodes.size();
    for(int v : nodes) {
        cout << " " << v;
    }
    cout << "\n";
    cout.flush();

    int x, d;
    cin >> x >> d;
    if(x == -1) exit(0);
    return {x, d};
}

void solve() {
    pair<int, int> pt = query(all);
    root = pt.first;
    dist = pt.second;
    dfs(root, 0, 0);
//cout<< "ROOT: " << root << " " "MAX_DEP: " << max_dep << endl;
    int lo = 0, up = max_dep, mid, u, v;
    while(lo < up) {
        mid = (lo + up + 1) >> 1;
//        cout<< "MID: " << mid << endl;
        pair<int, int> pt = query(dep[mid]);
        if(pt.second == dist) {
            u = pt.first;
            lo = mid;
        }
        else up = mid - 1;
    }

    vector<int> vec;
    dfs2(u, 0, 0, vec);
    v = query(vec).first;
    cout << "! " << u << " " << v << "\n";

    string s;
    cin >> s;
    if(s == "Incorrect") exit(0);
}

void init() {
    max_dep = 0;
    all.clear();
    for(int i = 1; i <= n; ++i) {
        all.push_back(i);
        G[i].clear();
        dep[i - 1].clear();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        init();
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        solve();
    }
    return 0;
}