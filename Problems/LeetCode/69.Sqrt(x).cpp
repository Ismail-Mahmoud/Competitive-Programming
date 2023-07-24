// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if(!x || x == 1) return x;
        int l = 1, r = x, m;
        while(l < r) {
            m = l + ((r - l + 1) >> 1);
            if(m <= x / m) l = m;
            else r = m - 1;
        }
        return l;
    }
};