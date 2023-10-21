// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss = evaluate(s);
        string tt = evaluate(t);
        return ss == tt;
    }

    string evaluate(const string& s) {
        string ret = "";
        for(char ch : s) {
            if(ch != '#') ret += ch;
            else if(!ret.empty()) ret.pop_back();
        }
        return ret;
    }
};
