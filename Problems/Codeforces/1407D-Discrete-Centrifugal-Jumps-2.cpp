#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 3e5 + 5, M = 1e6, K = 20;

int n, a[N], dp[N];
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
    dp[n - 1] = 0;
    for(int i = n - 2; ~i; --i) {
        dp[i] = n;
        for(int j : G[i]) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}