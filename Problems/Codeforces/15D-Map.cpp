// This solution doesn't pass under the original constraints
// Raise time to 7s and memory to 512MB

#include <bits/stdc++.h>

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'
#define DBGARR(a,n,t)   cerr<<#a<<": "; copy(a,a+n,ostream_iterator<t>(cerr," " )); cerr<<'\n'
#define DBGVEC(a,t)     cerr<<#a<<": "; copy(a.begin(),a.end(),ostream_iterator<t>(cerr," " )); cerr<<'\n'

#define ff  first
#define ss  second
#define mkp make_pair

using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

const int N = 1e3 + 3, LG = 10;

int n, m, a, b, bit[N][N], T[N][LG][N][LG], lg[N];
lld mat[N][N];

void build(){
    lg[0] = -1, lg[1] = 0;
    for(int i = 2; i < N; ++i)
        lg[i] = lg[i>>1] + 1;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            T[i][0][j][0] = mat[i][j];

    for(int h = 1; h < LG; ++h)
        for(int j = 0; j+(1<<h-1) < m; ++j)
            for(int i = 0; i < n; ++i)
                T[i][0][j][h] = min(T[i][0][j][h-1], T[i][0][j+(1<<h-1)][h-1]);

    for(int h = 0; h < LG; ++h)
        for(int j = 0; j+(1<<h)-1 < m; ++j)
            for(int v = 1; v < LG; ++v)
                for(int i = 0; i+(1<<v-1) < n; ++i)
                    T[i][v][j][h] = min(T[i][v-1][j][h], T[i+(1<<v-1)][v-1][j][h]);

    for(int i = 0; i < n; ++i)
        for(int j = 1; j < m; ++j)
            mat[i][j] += mat[i][j-1];

    for(int j = 0; j < m; ++j)
        for(int i = 1; i < n; ++i)
            mat[i][j] += mat[i-1][j];
}

int getMin(int i, int j, int ii, int jj){
    int h = lg[jj-j+1], v = lg[ii-i+1];
    return min({T[i][v][j][h], T[ii-(1<<v)+1][v][j][h], T[i][v][jj-(1<<h)+1][h], T[ii-(1<<v)+1][v][jj-(1<<h)+1][h]});
}

void upd(int i, int j){
    ++i, ++j;
    while(i < N){
        int jj = j;
        while(jj < N){
            ++bit[i][jj];
            jj += jj & -jj;
        }
        i += i & -i;
    }
}

void updRng(int i, int j, int ii, int jj){
    for(int x = i; x <= ii; ++x)
        for(int y = j; y <= jj; ++y)
            upd(x, y);
}

int get(int i, int j){
    ++i, ++j;
    int ret = 0;
    while(i){
        int jj = j;
        while(jj){
            ret += bit[i][jj];
            jj -= jj & -jj;
        }
        i -= i & -i;
    }
    return ret;
}

int getRng(int i, int j, int ii, int jj){
    return get(ii, jj) - get(i-1, jj) - get(ii, j-1) + get(i-1, j-1);
}

lld getSum(int i, int j, int ii, int jj){
    return mat[ii][jj] - (i? mat[i-1][jj] : 0) - (j? mat[ii][j-1] : 0) + (i&&j? mat[i-1][j-1] : 0);
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%lld", mat[i] + j);
    build();
    multiset<pair<lld, pii>> s;
    for(int i = 0; i+a-1 < n; ++i){
        for(int j = 0; j+b-1 < m; ++j){
            lld sum = getSum(i, j, i+a-1, j+b-1);
            int mn = getMin(i, j, i+a-1, j+b-1);
            s.insert(mkp(sum - 1LL * mn * a * b, mkp(i, j)));
            //DBG1(sum - mn * a * b);
        }
    }
    vector<pair<lld, pii>> v;
    for(auto p : s){
        lld ans = p.ff;
        int i = p.ss.ff, j = p.ss.ss;
        int ii = i+a-1, jj = j+b-1;
        //DBG4(ans, i, j, getRng(i, j, ii, jj));
        if(getRng(i, j, ii, jj)) continue;
        v.push_back(mkp(ans, mkp(i, j)));
        updRng(i, j, ii, jj);
    }
    printf("%d\n", v.size());
    for(auto p : v) printf("%d %d %lld\n", p.ss.ff+1, p.ss.ss+1, p.ff);
    return 0;
}
