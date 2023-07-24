// https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.size());
        sort(products.begin(), products.end());
        string sub = "";
        int offset = 0;
        for(int i = 0; i < searchWord.size(); ++i) {
            sub += searchWord[i];
            offset = lower_bound(products.begin() + offset, products.end(), sub) - products.begin();
            for(int j = offset; j < offset + 3 && j < products.size() && products[j].rfind(sub, 0) != string::npos; ++j) {
                ans[i].push_back(products[j]);
            }
        }
        return ans;
    }
};