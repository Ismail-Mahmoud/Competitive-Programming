# https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        moves = dict(A=0, B=0)
        for i in range(1, len(colors) - 1):
            moves[colors[i]] += colors[i - 1] == colors[i] == colors[i + 1]
        return moves["A"] > moves["B"]
