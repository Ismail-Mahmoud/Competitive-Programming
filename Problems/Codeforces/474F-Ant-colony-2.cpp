#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, LG = 20;

int n, q, a[N], T[N][LG], LOG[N];
vector<pair<int, int>> v;

void pre(){
    LOG[1] = 0;
    for(int i = 2; i < N; ++i)
        LOG[i] = LOG[i>>1] + 1;
}

void build(){
    for(int i = 0; i < n; ++i)
        T[i][0] = a[i];
    for(int k = 1; k < 20; ++k)
        for(int i = 0; i+(1<<(k-1)) < n; ++i)
            T[i][k] = __gcd(T[i][k-1], T[i+(1<<(k-1))][k-1]);
}

int get(int l, int r){
    int lg = LOG[r-l+1];
    return __gcd(T[l][lg], T[r-(1<<lg)+1][lg]);
}

int main()
{
    pre();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", a+i);
        v.push_back(pair<int, int>(a[i], i));
    }
    sort(v.begin(), v.end());
    build();
    scanf("%d", &q);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        int g = get(l, r), ans = r - l + 1;
        ans -= upper_bound(v.begin(), v.end(), pair<int, int>(g, r)) - lower_bound(v.begin(), v.end(), pair<int, int>(g, l));
        printf("%d\n", ans);
    }
    return 0;
}
