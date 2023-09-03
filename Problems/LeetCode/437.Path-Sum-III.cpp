// https://leetcode.com/problems/path-sum-iii/

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
public:
    int pathSum(TreeNode* root, int targetSum, long long sum = 0, bool new_start = true) {
        if(!root) return 0;
        sum += root->val;
        int cnt = sum == targetSum;
        cnt += pathSum(root->left, targetSum, sum, false);
        cnt += pathSum(root->right, targetSum, sum, false);
        if(new_start) {
            cnt += pathSum(root->left, targetSum, 0, true);
            cnt += pathSum(root->right, targetSum, 0, true);
        }
        return cnt;
    }
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum, vector<long long> prefixSum = {}) {
        if(!root) return 0;
        prefixSum.push_back(root->val + (prefixSum.empty()? 0 : prefixSum.back()));
        int cnt = calc(prefixSum, targetSum);
        cnt += pathSum(root->left, targetSum, prefixSum);
        cnt += pathSum(root->right, targetSum, prefixSum);
        return cnt;
    }

    int calc(const vector<long long>& prefixSum, int targetSum) {
        long long totalSum = prefixSum.back();
        int cnt = totalSum == targetSum;
        for(int i = 0; i < prefixSum.size() - 1; ++i) {
            cnt += totalSum - prefixSum[i] == targetSum;
        }
        return cnt;
    }
};
