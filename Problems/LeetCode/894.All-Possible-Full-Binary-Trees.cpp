// https://leetcode.com/problems/all-possible-full-binary-trees/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<TreeNode*> dp[20];
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n & 1)) {
            return {};
        }
        dp[1] = {new TreeNode()};
        for(int i = 3; i <= n; i += 2) {
            for(int l = 1; l < i; l += 2) {
                vector<TreeNode*>& leftSubTrees = dp[l];
                vector<TreeNode*>& rightSubTrees = dp[i - l - 1];
                for(TreeNode* left : leftSubTrees) {
                    for(TreeNode* right : rightSubTrees) {
                        dp[i].push_back(new TreeNode(0, left, right));
                    }
                }
            }
        }
        return dp[n];
    }
};