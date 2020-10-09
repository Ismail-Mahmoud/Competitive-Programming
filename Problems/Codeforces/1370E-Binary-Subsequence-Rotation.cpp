#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 2e5 + 5, K = 17, MOD = 1000000007;

int n;
set<int> S[2], dum = {-1};

set<int>::iterator get_next(int w, int idx) {
    auto it = S[w].upper_bound(idx);
    return it;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    string s, t;
    cin >> n >> s >> t;
    if(count(s.begin(), s.end(), '1') != count(t.begin(), t.end(), '1')) {
        return !printf("-1\n");
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == t[i]) continue;
        S[s[i] == '1'].insert(i);
    }
    int ans = 0;
    while(!S[0].empty()) {
        int w = *S[1].begin() < *S[0].begin(), idx = -1;
        set<int>::iterator it1, it2;
        while(true) {
            it1 = S[w].upper_bound(idx);
            it2 = S[!w].upper_bound(*it1);
            if(it1 == S[w].end() || it2 == S[!w].end()) {
                break;
            }
            idx = *it2;
            S[w].erase(it1);
            S[!w].erase(it2);
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}