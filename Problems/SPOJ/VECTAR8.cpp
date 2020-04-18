#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e6 + 5;

int ans[N];
bitset<N> isPrime;

void calc(int n){
    int p = 1e6;
    while(n / p == 0){
        p /= 10;
    }
    int tmp = n;
    while(p > 1){
        int left_digit = n / p;
        if(left_digit == 0){
            return;
        }
        n = n % p;
        if(!isPrime[n]){
            return;
        }
        p /= 10;
    }
    ans[tmp] = 1;
}

void sieve(){
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < N; ++i){
        if(isPrime[i]){
            calc(i);
            for(lld j = 1LL*i*i; j < N; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    sieve();
    for(int i = 1; i < N; ++i){
        ans[i] += ans[i-1];
    }
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
