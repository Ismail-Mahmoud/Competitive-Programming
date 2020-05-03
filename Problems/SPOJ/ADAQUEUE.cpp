#include <bits/stdc++.h>

using namespace std;

char z[20];

int main()
{
    deque<int> q;
    int n, x, r = 0;
    string s;
    scanf("%d", &n);
    while(n--){
        scanf("%s", &z);
        s = (z);
        if((s == "toFront" && !r) || (s == "push_back" && r)){
            scanf("%d", &x);
            q.push_front(x);
        }
        else if((s == "push_back" && !r) || (s == "toFront" && r)){
            scanf("%d", &x);
            q.push_back(x);
        }
        else if((s == "front" && !r) || (s == "back" && r)){
            if(q.empty()) puts("No job for Ada?");
            else printf("%d\n", q.front()), q.pop_front();
        }
        else if((s == "back" && !r) || (s == "front" && r)){
            if(q.empty()) puts("No job for Ada?");
            else printf("%d\n", q.back()), q.pop_back();
        }
        else r ^= 1;
    }
    return 0;
}
