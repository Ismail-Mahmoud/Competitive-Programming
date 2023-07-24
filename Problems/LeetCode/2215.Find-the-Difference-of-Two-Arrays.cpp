// https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff1, diff2;
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        for(auto x : set1) {
            if(set2.find(x) == set2.end()) {
                diff1.push_back(x);
            }
        }
        for(auto x : set2) {
            if(set1.find(x) == set1.end()) {
                diff2.push_back(x);
            }
        }
        return {diff1, diff2};
    }
};