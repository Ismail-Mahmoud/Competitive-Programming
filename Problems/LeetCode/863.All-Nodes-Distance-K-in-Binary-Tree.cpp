// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> adj[501];
    bool vis[501];
    vector<int> ans;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build_graph(root);
        dfs(target->val, 0, k);
        return ans;
    }
    void build_graph(TreeNode* node) {
        if(!node) return;
        addEdge(node, node->left);
        addEdge(node, node->right);
        build_graph(node->left);
        build_graph(node->right);
    }
    void addEdge(TreeNode* node, TreeNode* child) {
        if(!child) return;
        int u = node->val, v = child->val;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int dist, int target_dist) {
        vis[u] = true;
        if(dist == target_dist) {
            ans.push_back(u);
            return;
        }
        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v, dist + 1, target_dist);
            }
        }
    }
};