#include <bits/stdc++.h>

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

#define ff      first
#define ss      second
#define all(v)  v.begin(), v.end()

using namespace std;

typedef long long lld;

const int N = 1e5 + 5, M = N << 1, K = 17, MOD = 1000000007;

int n, m;
vector<int> ans;
priority_queue<pair<int, int>> D;

struct Friend {
    int X, Y;
    bool done;
    Friend(): X(0), Y(0), done(false) {}
    Friend(int x, int y, bool d): X(x), Y(y), done(d) {}
} frnd[M];

struct Food {
    int dif, cnt;
    bool done;
    vector<int> adj;
    Food(): dif(0), cnt(0), done(false), adj({}) {}
} food[N];

void Insert(set<pair<int, int>>& S, int x) {
    auto it = S.lower_bound({x, 0});
    if(it == S.end() || it->ff != x) S.insert({x, 1});
    else{
        S.insert({x, it->ss + 1});
        S.erase(it);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int c;
        scanf("%d", &c);
        food[i].cnt = c;
    }
    for(int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        frnd[i] = Friend(x, y, false);
        food[x].adj.push_back(i);
        food[y].adj.push_back(i);
    }
    for(int i = 1; i <= n; ++i) {
        auto& F = food[i];
        if(F.adj.empty()) continue;
        F.done = false;
        F.dif = F.cnt - (int)F.adj.size();
        D.push({F.dif, i});
        //DBG2(F.dif, i);
    }
    while(!D.empty()) {
        pair<int, int> pt = D.top();
        D.pop();
        int dif = pt.ff, typ = pt.ss;
        if(food[typ].done) continue;
        if(dif < 0) exit(puts("DEAD"));
        food[typ].done = true;
        set<pair<int, int>> upd;
        for(int& f : food[typ].adj) {
            auto& F = frnd[f];
            if(F.done) continue;
            F.done = true;
            ans.push_back(f);
            if(!food[F.X].done) Insert(upd, F.X);
            if(!food[F.Y].done) Insert(upd, F.Y);
        }
        for(auto it : upd) {
            int x = it.ff, cnt = it.ss;
            food[x].dif += cnt;
            D.push({food[x].dif, x});
        }
    }
    puts("ALIVE");
    for(vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) {
        printf("%d%c", *it, " \n"[it == ans.rend()]);
    }
    return 0;
}