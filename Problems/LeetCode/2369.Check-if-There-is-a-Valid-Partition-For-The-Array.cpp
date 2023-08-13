class Solution {
    int mem[100001];
public:
    bool validPartition(vector<int>& nums) {
        memset(mem, -1, sizeof(mem));
        return dp(0, nums);
    }

    bool dp(int i, const vector<int>& nums) {
        return i == nums.size()? true
                : ~mem[i]? mem[i]
                : mem[i] = (equal(i, 2, nums) && dp(i + 2, nums))
                        || (equal(i, 3, nums) && dp(i + 3, nums))
                        || (consecutive(i, 3, nums) && dp(i + 3, nums));
    }

    bool equal(int i, int len, const vector<int>& nums) {
        if(i + len - 1 >= nums.size()) return false;
        for(int k = i; k < i + len; ++k) {
            if(nums[k] != nums[i]) return false;
        }
        return true;
    }

    bool consecutive(int i, int len, const vector<int>& nums) {
        if(i + len - 1 >= nums.size()) return false;
        for(int k = i + 1; k < i + len; ++k) {
            if(nums[k] != nums[k - 1] + 1) return false;
        }
        return true;
    }
};
