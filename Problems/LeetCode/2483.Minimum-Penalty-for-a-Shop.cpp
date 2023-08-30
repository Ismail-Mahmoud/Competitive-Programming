// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> LN(n + 1, 0), RY(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            LN[i + 1] = LN[i] + (customers[i] == 'N');
        }
        for(int i = n - 1; ~i; --i) {
            RY[i] = RY[i + 1] + (customers[i] == 'Y');
        }
        int min_pen = INT_MAX, idx;
        for(int i = 0, pen; i <= n; ++i) {
            pen = LN[i] + RY[i];
            if(pen < min_pen) {
                min_pen = pen;
                idx = i;
            }
        }
        return idx;
    }
};
