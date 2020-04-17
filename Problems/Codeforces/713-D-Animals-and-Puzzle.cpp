#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, K = 10;

int n, m, q, a[N][N], T[N][K][N][K], lg[N];

void build(){
    lg[0] = -1, lg[1] = 0;
    for(int i = 2; i <= max(n, m); ++i)
        lg[i] = lg[i>>1] + 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            T[i][0][j][0] = a[i][j];

    for(int i = 1; i <= n; ++i)
        for(int h = 1; (1<<h) <= m; ++h)
            for(int j = 1; j+(1<<h)-1 <= m; ++j)
                T[i][0][j][h] = max(T[i][0][j][h-1], T[i][0][j+(1<<h-1)][h-1]);

    for(int h = 0; (1<<h) <= m; ++h)
        for(int j = 1; j+(1<<h)-1 <= m; ++j)
            for(int v = 1; (1<<v) <= n; ++v)
                for(int i = 1; i+(1<<v)-1 <= n; ++i)
                    T[i][v][j][h] = max(T[i][v-1][j][h], T[i+(1<<v-1)][v-1][j][h]);
}

int get(int i, int j, int ii, int jj){
    int h = lg[jj-j+1], v = lg[ii-i+1];
    return max({T[i][v][j][h], T[i][v][jj-(1<<h)+1][h], T[ii-(1<<v)+1][v][j][h], T[ii-(1<<v)+1][v][jj-(1<<h)+1][h]});
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", a[i] + j);
            // max square ending at (i, j)
            if(a[i][j]) a[i][j] = min({a[i-1][j], a[i][j-1], a[i-1][j-1]}) + 1;
        }
    }
    build();
    scanf("%d", &q);
    while(q--){
        int i, j, ii, jj;
        scanf("%d %d %d %d", &i, &j, &ii, &jj);
        int lo = 0, hi = min(ii-i+1, jj-j+1), mid;
        while(lo < hi){
            mid = (lo + hi + 1) >> 1;
            // if the answer is x, it must be get only from the rect (i+x-1, j+x-1), (ii, jj)
            if(get(i+mid-1, j+mid-1, ii, jj) >= mid) lo = mid;
            else hi = mid - 1;
        }
        printf("%d\n", lo);
    }
    return 0;
}
