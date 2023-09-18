# https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        lst = [i for i in range(len(mat))]
        lst.sort(key=lambda i: sum(mat[i]))
        return lst[:k]
