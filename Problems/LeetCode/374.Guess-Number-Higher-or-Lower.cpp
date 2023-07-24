// https://leetcode.com/problems/guess-number-higher-or-lower/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 0, hi = n, m, res;
        while(lo < hi) {
            m = lo + ((hi - lo) >> 1);
            res = guess(m);
            if(res == -1) {
                hi = m - 1;
            }
            else if(res == 1) {
                lo = m + 1;
            }
            else {
                return m;
            }
        }
        return lo;
    }
};