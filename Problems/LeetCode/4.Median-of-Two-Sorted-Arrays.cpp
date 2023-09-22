// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) {
            swap(nums1, nums2);
            swap(n, m);
        }
        int total = n + m;
        int CNT = (total + 1) >> 1;     // #element before & including the (first) median in the sorted array
        int lo = 0, hi = min(n, CNT);
        while(lo < hi) {
            int cnt1 = (lo + hi) >> 1;  // #elements taken from nums1
            int cnt2 = CNT - cnt1;      // #elements taken from nums2
            if(need_more_from_nums1(cnt1, cnt2, nums1, nums2)) {
                lo = cnt1 + 1;
            }
            else {
                hi = cnt1;
            }
        }
        int cnt1 = lo;
        int cnt2 = CNT - cnt1;
        int med = get_median(cnt1, cnt2, nums1, nums2);
        if(total & 1) {
            return med;
        }
        int next_med = get_next_median(cnt1, cnt2, nums1, nums2);
        return 1.0 * (med + next_med) / 2;
    }

    bool need_more_from_nums1(int cnt1, int cnt2, const vector<int>& nums1, const vector<int>& nums2) {
        // next element (not taken) in nums1 < last element taken from nums2
        return cnt2 > 0 && nums1[cnt1] < nums2[cnt2 - 1];
    }

    int get_median(int cnt1, int cnt2, const vector<int>& nums1, const vector<int>& nums2) {
        if(!cnt1) return nums2[cnt2 - 1];
        if(!cnt2) return nums1[cnt1 - 1];
        return max(nums1[cnt1 - 1], nums2[cnt2 - 1]);
    }

    int get_next_median(int cnt1, int cnt2, const vector<int>& nums1, const vector<int>& nums2) {
        if(cnt1 == nums1.size()) return nums2[cnt2];
        if(cnt2 == nums2.size()) return nums1[cnt1];
        return min(nums1[cnt1], nums2[cnt2]);
    }
};
