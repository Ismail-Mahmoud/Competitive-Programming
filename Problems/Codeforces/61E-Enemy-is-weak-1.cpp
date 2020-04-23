#include <bits/stdc++.h>

#define ff      first
#define ss      second
#define all(v)  v.begin(), v.end()

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n';
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n';
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n';
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n';

using namespace std;

typedef long long lld;

const int N = 1e6 + 9;

int n, m, k;
map<int, int> mp;
int ID, A[N], bit[N], L[N], R[N];

void update(int idx, int val){
    while(idx < N){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int get(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios::sync_with_stdio(false); cin.tie(nullptr);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);
        mp[x] = i;
    }
    for(auto it : mp){
        A[it.ss] = ++ID;
    }
    for(int i = 1; i <= n; ++i){
        L[i] = get(ID) - get(A[i]);
        update(A[i], 1);
    }
    memset(bit, 0, sizeof bit);
    lld res = 0;
    for(int i = n; i; --i){
        R[i] = get(A[i]-1);
        update(A[i], 1);
        res += 1LL * L[i] * R[i];
    }
    //for(int i = 1; i <= n; ++i) DBG3(A[i], L[i], R[i]);
    printf("%lld\n", res);
    return 0;
}
