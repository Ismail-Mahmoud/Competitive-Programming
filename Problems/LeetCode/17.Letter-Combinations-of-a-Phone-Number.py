# https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution:
    letters = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        combinations = self.letterCombinations(digits[1:]) or [""]
        return [
            letter + string
            for letter in self.letters[digits[0]]
            for string in combinations
        ]
