// https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = __gcd(str1.size(), str2.size());
        string substr1 = str1.substr(0, g);
        string substr2 = str2.substr(0, g);
        if(substr1 == substr2 && divides(substr1, str1) && divides(substr2, str2)) {
            return str1.substr(0, g);
        }
        return "";
    }
    bool divides(string substr, string str) {
        for(int i = 0; i < substr.size(); ++i) {
            for(int j = i; j < str.size(); j += substr.size()) {
                if(str[i] != str[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};