// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
    vector<int> group[501];
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        for(int i = 0, sz; i < groupSizes.size(); ++i) {
            sz = groupSizes[i];
            group[sz].push_back(i);
            if(group[sz].size() == sz) {
                ans.push_back(group[sz]);
                group[sz].clear();
            }
        }
        return ans;
    }
};
