// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(auto it = digits.rbegin(); carry && it != digits.rend(); ++it) {
            *it += carry;
            if(*it == 10) {
                *it = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};