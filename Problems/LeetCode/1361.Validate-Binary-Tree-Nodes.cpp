// https://leetcode.com/problems/validate-binary-tree-nodes/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; ++i) {
            int l = leftChild[i], r = rightChild[i];
            if(~l) ++inDegree[l];
            if(~r) ++inDegree[r];
        }
        int root = -1;
        for(int i = 0; i < n; ++i) {
            if(inDegree[i] > 1) return false;
            if(!inDegree[i]) {
                if(~root) return false;
                root = i;
            }
        }
        if(root == -1) return false;
        if(dfs(root, leftChild, rightChild) < n) return false;
        return true;
    }

    int dfs(int u, vector<int>& leftChild, vector<int>& rightChild) {
        if(u == -1) return 0;
        int cnt = 1;
        cnt += dfs(leftChild[u], leftChild, rightChild);
        cnt += dfs(rightChild[u], leftChild, rightChild);
        return cnt;
    }
};
