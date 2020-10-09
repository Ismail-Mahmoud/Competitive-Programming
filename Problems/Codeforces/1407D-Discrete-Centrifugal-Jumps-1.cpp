#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 3e5 + 5, M = 1e6, K = 20;

int n, a[N];
vector<int> G[N];

void addEdge(int i, int j, bool rev) {
    if(!rev) {
        G[i].push_back(j);
        //cout<<i<<" "<<j<<endl;
        return;
    }
    int ii = n - j - 1;
    int jj = n - i - 1;
    //cout<<ii<<" "<<jj<<endl;
    G[ii].push_back(jj);
}

void findNext(int gt, int rev) {
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && gt*a[i] >= gt*a[st.top()]) {
            addEdge(st.top(), i, rev);
            st.pop();
        }
        st.push(i);
    }
    //puts("");
}

int bfs() {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    int l = 0;
    while(!q.empty()) {
        int k = q.size();
        while(k--) {
            int u = q.front();
            if(u == n - 1) return l;
            q.pop();
            for(int v : G[u]) {
                if(vis[v]) continue;
                vis[v] = true;
                q.push(v);
            }
        }
        ++l;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    findNext(1, 0);     // Next element >= a[i]
    findNext(-1, 0);    // Next element <= a[i]
    reverse(a, a + n);
    findNext(1, 1);     // Prev element >= a[i]
    findNext(-1, 1);    // Prev element <= a[i]
    printf("%d\n", bfs());
    return 0;
}