// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while(true) {
            while(l < r && !vowel(s[l])) ++l;
            while(l < r && !vowel(s[r])) --r;
            if(l < r) swap(s[l++], s[r--]);
            else break;
        }
        return s;
    }
    bool vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};