// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it_zero = nums.begin(), it_num = nums.begin();
        while(true) {
            while(it_num != nums.end() && *it_num == 0) {
                ++it_num;
            }
            if(it_num == nums.end()) {
                break;
            }
            while(it_zero != nums.end() && *it_zero != 0) {
                ++it_zero;
            }
            if(it_zero == nums.end()) {
                break;
            }
            if(it_zero < it_num){
                swap(*it_num, *it_zero);
                ++it_num; ++it_zero;
            }
            else {
                ++it_num;
            }
        }
    }
};