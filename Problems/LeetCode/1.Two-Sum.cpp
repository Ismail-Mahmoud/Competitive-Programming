class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = idx.find(target - nums[i]);
            if(it != idx.end()) {
                return {it->second, i};
            }
            idx[nums[i]] = i;

        }
        assert(false);
        return {};
    }
};
