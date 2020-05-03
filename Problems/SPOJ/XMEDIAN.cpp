#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> s;

int main()
{
    int n, x, sz = 0, id = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        s.insert({x, ++id});
        printf("%d\n", s.find_by_order(sz++>>1)->first);
    }
    return 0;
}
