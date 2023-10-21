# https://leetcode.com/problems/pascals-triangle-ii/

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = []
        for r in range(rowIndex + 1):
            row = [1 if c == 0 or c == r else row[c - 1] + row[c] for c in range(0, r + 1)]
        return row
