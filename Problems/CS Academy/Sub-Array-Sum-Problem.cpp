//https://csacademy.com/ieeextreme-practice/task/46e8a03f242b875f1ae5fb84a3b4321f/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v5;
typedef vector<v5> v4;
typedef vector<v4> v3;
typedef vector<v3> v2;
typedef vector<v2> v1;

int d;
vector<int> dim(6, 1);

void go(int da, int db, int dc, int dd, int de, v1& A){
    for(int a = 1; a <= dim[1]; ++a)
    for(int b = 1; b <= dim[2]; ++b)
    for(int c = 1; c <= dim[3]; ++c)
    for(int d = 1; d <= dim[4]; ++d)
    for(int e = 1; e <= dim[5]; ++e)
        A[a][b][c][d][e] += A[a-da][b-db][c-dc][d-dd][e-de];
}
/**
    x y
    0 0 +(xr, yr)
    0 1 -(xr, yl-1)
    1 0 -(xl-1, yr)
    1 1 +(xl-1, yl-1)

    a b c d e
    0 0 0 0 0 +(ar, br, cr, dr, er)
    0 1 1 0 1 -(ar, bl-1, cl-1, dr, el-1)
    1 1 0 0 0 +(al-1, bl-1, cr, dr, er)
**/
int get(vector<int>& L, vector<int>& R, v1& A){
    int ret = 0;
    for(int msk = 0; msk < 32; ++msk){
        int id[5];
        for(int k = 0; k < 5; ++k){
            if(msk & (1 << k)) id[k] = L[k]-1;
            else id[k] = R[k];
        }
        if(__builtin_popcount(msk) & 1) ret -= A[id[0]][id[1]][id[2]][id[3]][id[4]];
        else ret += A[id[0]][id[1]][id[2]][id[3]][id[4]];
    }
    return ret;
}

int main()
{
    scanf("%d", &d);
    for(int i = 1; i <= d; ++i)
        scanf("%d", &dim[i]);
    v5 d5(dim[5]+1, 0);
    v4 d4(dim[4]+1, d5);
    v3 d3(dim[3]+1, d4);
    v2 d2(dim[2]+1, d3);
    v1 A(dim[1]+1, d2);
    for(int a = 1; a <= dim[1]; ++a)
    for(int b = 1; b <= dim[2]; ++b)
    for(int c = 1; c <= dim[3]; ++c)
    for(int d = 1; d <= dim[4]; ++d)
    for(int e = 1; e <= dim[5]; ++e)
        scanf("%d", &A[a][b][c][d][e]);
    go(1, 0, 0, 0, 0, A);
    go(0, 1, 0, 0, 0, A);
    go(0, 0, 1, 0, 0, A);
    go(0, 0, 0, 1, 0, A);
    go(0, 0, 0, 0, 1, A);
    int q;
    scanf("%d", &q);
    while(q--){
        vector<int> L(5, 1), R(5, 1);
        for(int i = 0; i < d; ++i) scanf("%d", &L[i]);
        for(int i = 0; i < d; ++i) scanf("%d", &R[i]);
        printf("%d\n", get(L, R, A));
    }
    return 0;
}
