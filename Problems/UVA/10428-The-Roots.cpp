// UVA 10428 - The Roots

#include <bits/stdc++.h>

#define all(v)  v.begin(), v.end()

using namespace std;

typedef vector<long double> vdd;

const long double EPS = 1e-10, OO = 1e14;

bool cmp(long double a, long double b){
    return fabs(a - b) < EPS;
}

void print(vdd d, int id = -1){
    sort(all(d), cmp);
    cout << "Equation " << id << ": " << d[0];
    long double p = d[0];
    for(int i = 1; i < d.size(); ++i){
        if(cmp(d[i], p)) continue;
        cout << " " << d[i], p = d[i];
    }
    cout << "\n";
}

vdd derivative(vdd eq){
    int deg = eq.size() - 1;
    vdd ret;
    for(int i = 0; i < eq.size() - 1; ++i){
        ret.push_back(deg-- * eq[i]);
    }
    return ret;
}

long double f(vdd eq, long double x){
    long double ret = 0;
    int deg = eq.size() - 1;
    for(int i = 0; i < eq.size(); ++i){
        ret += eq[i] * pow(x, deg--);
    }
    return ret;
}

long double intervalRoot(vdd eq, long double l, long double r){
    long double x = (l + r) / 2;
    while(1){
        long double nx = x - f(eq, x) / f(derivative(eq), x);
        if(cmp(x, nx)) break;
        x = nx;
    }
    return x;
}

vdd findRoots(vdd eq){
    if(eq.size() == 1) return {};
    vdd tmp = findRoots(derivative(eq)), ret, roots;
    roots.push_back(-OO);
    copy(all(tmp), back_inserter(roots));
    roots.push_back(OO);
    sort(all(roots));
    for(int i = 0; i < (int)roots.size() - 1; ++i){
        if(cmp(roots[i], roots[i + 1])) continue;
        long double r = intervalRoot(eq, roots[i], roots[i + 1]);
        ret.push_back(r);
    }
    return ret;
}

int main()
{
    cout << fixed << setprecision(4);
    int n, id = 0;
    while(cin >> n, n){
        vdd eq(n + 1);
        for(long double& x : eq) cin >> x;
        vdd e = eq;
        print(findRoots(eq), ++id);
    }
    return 0;
}
