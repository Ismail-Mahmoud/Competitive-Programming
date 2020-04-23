#include <bits/stdc++.h>

using namespace std;

char in[10];
string s[10];
int n, k, num, mi, mx, ans, pos[10];

int get(int i){
    int ret = 0;
    for(int p = 0; p < k; ++p)
        ret = ret * 10 + s[i][pos[p]] - '0';
    return ret;
}

int main()
{
    ans = 2e9;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%s", in);
        s[i] = in;
    }
    iota(pos, pos + k, 0);
    do{
        mi = 2e9, mx = -1;
        for(int i = 0; i < n; ++i){
            num = get(i);
            mi = min(mi, num);
            mx = max(mx, num);
        }
        ans = min(ans, mx - mi);
    }while(next_permutation(pos, pos + k));
    printf("%d\n", ans);
    return 0;
}
