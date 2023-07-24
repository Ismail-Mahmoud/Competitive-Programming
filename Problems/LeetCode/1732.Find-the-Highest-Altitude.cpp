// https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h = 0, max_h = 0;
        for(int d : gain) {
            max_h = max(max_h, h += d);
        }
        return max_h;
    }
};