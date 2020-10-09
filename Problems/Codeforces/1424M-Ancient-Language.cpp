#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, M = 1e6 + 5, K = 20, MOD = 1000000007;

typedef long long lld;

int n, k, vis[30];
char in[105];
bool f[30];
vector<string> A;
vector<int> G[30];
string ans;

void EXIT() {
    puts("IMPOSSIBLE");
    exit(0);
}

void addEdge(char u, char v) {
    G[u - 'a'].push_back(v - 'a');
}

void match(const string& a, const string& b) {
    for(int i = 0; i < min(a.size(), b.size()); ++i) {
        if(a[i] == b[i]) continue;
        addEdge(a[i], b[i]);
        return;
    }
    if(a.size() > b.size()) EXIT();
}

void constructGraph() {
    n *= k;
    for(int i = 0; i < n - 1; ++i) {
        match(A[i], A[i + 1]);
    }
}

void dfs(int u) {
    vis[u] = 2;
    for(int v : G[u]) {
        if(vis[v] == 2) EXIT();
        if(vis[v] == 1) continue;
        dfs(v);
    }
    vis[u] = 1;
    ans.push_back(u + 'a');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &k);
    A.resize(n * k);
    for(int i = 0; i < n; ++i) {
        int p;
        scanf("%d", &p);
        for(int j = 0; j < k; ++j) {
            scanf("%s", in);
            A[p * k + j] = in;
            for(int l = 0; in[l]; ++l) {
                f[in[l] - 'a'] = true;
            }
        }
    }
    constructGraph();
    for(int i = 0; i < 26; ++i) {
        if(vis[i] || G[i].empty()) continue;
        dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < 26; ++i) {
        if(f[i] && ans.find(i + 'a') == string::npos) {
            ans.push_back(i + 'a');
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}