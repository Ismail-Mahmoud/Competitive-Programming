// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber) {
            --columnNumber;
            ans += 'A' + columnNumber % 26;
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
