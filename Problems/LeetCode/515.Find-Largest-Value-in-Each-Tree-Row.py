# https://leetcode.com/problems/find-largest-value-in-each-tree-row/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        q, ans = [root], []
        while q:
            ans.append(max(q, key=lambda node: node.val).val)
            q = [child for node in q for attr in ("left", "right") if (child := getattr(node, attr))]
        return ans
