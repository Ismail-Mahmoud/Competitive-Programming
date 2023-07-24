// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for(int l = 0, r = s.size() - 1; l < r; ++l, --r) {
            if(s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
};