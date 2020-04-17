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

const int N = 1e5 + 3;

int sz[3];
vector<vector<int>> A;
lld ans;

lld calc(lld x, lld y, lld z){
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

vector<int> get(int x, int k){
    vector<int> ret;
    auto it = lower_bound(all(A[k]), x);
    if(it != A[k].end()){
        ret.push_back(*it);
        if(it+1 != A[k].end()) ret.push_back(*(it+1));
    }
    if(it != A[k].begin()) ret.push_back(*(it-1));
//    DBG2(x, k);
//    DBGVEC(ret,int);
    return ret;
}

void solve(int k){
    vector<int> F, S;
    for(int x : A[k]){
        F = get(x, (k+1)%3);
        for(int y : F){
            S = get(y, (k+2)%3);
            for(int z : S){
                ans = min(ans, calc(x, y, z));
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    A.resize(3);
    while(t--){
        ans = 8e18;
        for(int k = 0; k < 3; ++k){
            scanf("%d", sz + k);
            A[k].resize(sz[k]);
        }
        for(int k = 0; k < 3; ++k){
            for(int i = 0; i < sz[k]; ++i){
                scanf("%d", &A[k][i]);
            }
            sort(all(A[k]));
        }
        for(int k = 0; k < 3; ++k){
            solve(k);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
