// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

class Solution {
public:
    string largestGoodInteger(string num) {
        char dig = 0;
        for(int i = 0; i < num.size() - 2; ++i) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2] && num[i] > dig) {
                dig = num[i];
            }
        }
        return dig? string(3, dig) : "";
    }
};
