#include <bits/stdc++.h>

#define ff      first
#define ss      second
#define mkp(a,b)make_pair(a,b)
#define all(v)  v.begin(), v.end()

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

using namespace std;

typedef long long lld;

const int N = 2e5 + 3;

int n, k, sz[N], L[N];
vector<int> G[N];

int dfs(int u, int p, int l){
    sz[u] = 1;
    L[u] = l;
    for(int v : G[u]){
        if(v == p) continue;
        sz[u] += dfs(v, u, l+1);
    }
    return sz[u];
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n-1; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1, 0);
    vector<int> v;
    for(int i = 1; i <= n; ++i){
        v.push_back(L[i] - (sz[i]-1));
    }
    sort(all(v));
    lld ans = 0;
    for(int i = v.size()-1; ~i && k; --i, --k){
        ans += v[i];
    }
    printf("%lld\n", ans);
    return 0;
}
