// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, idx = 0;
        for(int i = 0, j; i < chars.size();) {
            j = i;
            while(j < chars.size() && chars[i] == chars[j]) {
                ++j;
            }
            add(chars, idx, chars[i], j - i);
            i = j;
        }
        return idx;
    }

    void add(vector<char>& chars, int& idx, char ch, int cnt) {
        chars[idx++] = ch;
        if(cnt == 1) {
            return;
        }
        int beg = idx;
        while(cnt) {
            chars[idx++] = cnt % 10 + '0';
            cnt /= 10;
        }
        reverse(chars.begin() + beg, chars.begin() + idx);
    }
};