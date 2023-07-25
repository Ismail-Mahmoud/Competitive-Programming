// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2, m;
        while(l < r) {
            m = (l + r) >> 1;
            if(arr[m + 1] > arr[m]) l = m + 1;
            else if(arr[m - 1] > arr[m]) r = m - 1;
            else return m;
        }
        return l;
    }
};