// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word) {
            words.push_back(word);
        }
        string ans = "";
        for(auto it = words.rbegin(); it != words.rend(); ++it) {
            ans += *it;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};