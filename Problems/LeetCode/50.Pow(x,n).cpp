// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while(n > 0) {
            if(n & 1) ans *= x;
            x = x * x;
            n >>= 1;
        }
        while(n < 0) {
            if(n & 1) ans /= x, ++n;
            x = x * x;
            n >>= 1;
        }
        return ans;
    }
};