// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && __builtin_popcount(n) == 1 && __builtin_popcount(n - 1) % 2 == 0;
    }
};
