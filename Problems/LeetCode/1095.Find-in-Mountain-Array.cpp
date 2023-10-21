// https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int idx = findTarget(target, mountainArr, 0, peak, 1);
        if(idx == -1) {
            idx = findTarget(target, mountainArr, peak + 1, mountainArr.length() - 1, -1);
        }
        return idx;
    }

    int findPeak(MountainArray &arr) {
        int l = 1, r = arr.length() - 2;
        while(l < r) {
            int m = (l + r) >> 1;
            if(arr.get(m) < arr.get(m + 1)) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    int findTarget(int target, MountainArray &arr, int l, int r, int factor) {
        target *= factor;
        while(l < r) {
            int m = (l + r) >> 1;
            int x = getElement(arr, m, factor);
            if(x < target) l = m + 1;
            else if(x > target) r = m - 1;
            else return m;
        }
        return getElement(arr, l, factor) == target? l : -1;
    }

    int getElement(MountainArray &arr, int idx, int factor) {
        return arr.get(idx) * factor;
    }
};
