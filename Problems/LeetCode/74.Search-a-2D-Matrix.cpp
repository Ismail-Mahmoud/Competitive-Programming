// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n * m - 1, mid, num;
        while(lo <= hi) {
            mid = (lo + hi) >> 1;
            num = matrix[mid / m][mid % m];
            if(num < target) lo = mid + 1;
            else if(num > target) hi = mid - 1;
            else return true;
        }
        return false;
    }
};
