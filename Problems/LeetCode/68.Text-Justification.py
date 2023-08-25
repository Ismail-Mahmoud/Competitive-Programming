# https://leetcode.com/problems/text-justification/

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        line = Line(max_width=maxWidth)
        for word in words:
            if line.add_word(word):
                continue
            text = line.text()
            ans.append(text)
            line = Line(max_width=maxWidth, words=[word])
        text = line.text(fully_justify=False)
        ans.append(text)
        return ans


class Line:
    def __init__(self, max_width: int, words=[]):
        self.max_width = max_width
        self.__words: List[str] = []
        self.__num_chars: int = 0
        for word in words:
            self.add_word(word)

    def __len__(self):
        num_spaces = len(self.__words) - 1
        return self.__num_chars + num_spaces
    
    def add_word(self, word: str) -> bool:
        if self.__len__() + len(word) + 1 > self.max_width:
            return False
        self.__words.append(word)
        self.__num_chars += len(word)
        return True

    def text(self, fully_justify=True) -> str:
        if not fully_justify or len(self.__words) == 1 or self.__len__() == self.max_width:
            return " ".join(self.__words).ljust(self.max_width)
        
        slots = len(self.__words) - 1
        total_spaces = self.max_width - self.__num_chars
        spaces_between_words, remaining_spaces = divmod(total_spaces, slots)
        text = ""
        for word in self.__words[:-1]:
            text += word
            text += " " * (spaces_between_words + (remaining_spaces > 0))
            remaining_spaces -= 1
        text += self.__words[-1]

        assert len(text) == self.max_width
        assert text[-1] != " " or len(self.__words) == 1 or not fully_justify
        
        return text
