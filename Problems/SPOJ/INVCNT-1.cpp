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
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<lld> vll;
typedef pair<lld, lld> pll;
typedef vector<pair<lld, lld>> vpll;

const int N = 2e5 + 9, MOD = 1e9 + 7, OO = 0x3f3f3f3f;

int n, a[N];

lld sort(int* arr, int l, int r){
    if(l == r - 1) return 0;
    int m = (l + r) >> 1;
    lld ret = 0;
    ret += sort(arr, l, m);
    ret += sort(arr, m, r);
    int * tmp = new int[r - l];
    int * i = arr + l, * j = arr + m, * k = tmp;
    while(i < arr + m && j < arr + r){
        if(*i < *j) *k++ = *i++;
        else *k++ = *j++, ret += arr + m - i;
    }
    while(i < arr + m){
        *k++ = *i++;
    }
    while(j < arr + r){
        *k++ = *j++;
    }
    copy(tmp, tmp + r - l, arr + l);
    delete []tmp;
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        lld inv = sort(a, 0, n);
        printf("%lld\n", inv);
    }
    return 0;
}

