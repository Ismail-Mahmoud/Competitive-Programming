#include <bits/stdc++.h>

#define ff      first
#define ss      second

#define DBG1(a)         cerr<<#a<<":"<<(a)<<'\n'
#define DBG2(a,b)       cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<'\n'
#define DBG3(a,b,c)     cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<'\n'
#define DBG4(a,b,c,d)   cerr<<#a<<":"<<(a)<<"  "<<#b<<":"<<(b)<<"  "<<#c<<":"<<(c)<<"  "<<#d<<":"<<(d)<<'\n'

using namespace std;

typedef long long lld;
typedef pair<long long, long long> pll;

const lld N = 1e5 + 9, M = 2e15;

lld n, d, a[N], par[N], len[N];

struct Node{
    pll mx;
    Node * left, * right;
    Node(){
        mx = {0, 0};
        left = right = nullptr;
    }
};

pll update(Node* node, lld l, lld r, lld w, lld v, lld i){
    if(l > r || l > w || r < w) return node->mx;
    if(l == r) return node->mx = {v, i};

    if(node->left == nullptr) node->left = new Node();
    if(node->right == nullptr) node->right = new Node();

    lld m = (l + r) >> 1;
    pll L = update(node->left, l, m, w, v, i);
    pll R = update(node->right, m+1, r, w, v, i);

    return node->mx = max(L, R);
}

pll get(Node* node, lld l, lld r, lld ql, lld qr){
    if(l > r || r < ql || l > qr || node == nullptr) return {0, 0};
    if(l >= ql && r <= qr) return node->mx;

    lld m = (l + r) >> 1;
    pll L = get(node->left, l, m, ql, qr);
    pll R = get(node->right, m+1, r, ql, qr);

    return max(L, R);
}

void print(lld i){
    if(!i) return;
    print(par[i]);
    printf("%lld ", i);
}

int main()
{
    scanf("%lld %lld", &n, &d);
    for(lld i = 1; i <= n; ++i)
        scanf("%lld", a+i);
    Node* root = new Node();
    for(lld i = 1; i <= n; ++i){
        pll p1 = get(root, 1, M, 1, a[i]-d);
        pll p2 = get(root, 1, M, a[i]+d, M);
        pll m = max(p1, p2);
        par[i] = m.ss;
        update(root, 1, M, a[i], m.ff+1, i);
    }
    printf("%lld\n", root->mx.ff);
    print(root->mx.ss);
    return 0;
}
