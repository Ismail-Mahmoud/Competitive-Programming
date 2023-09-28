class Solution:
    class Tape:
        # tape = repeated pattern + word
        def __init__(self, last_word: str, pattern_len: int, total_len: int) -> None:
            self.last_word = last_word
            self.pattern_len = pattern_len
            self.total_len = total_len

    def solve(self, tapes: list[Tape], idx: int):
        for i in range(len(tapes) - 1, 0, -1):
            cur_tape, prev_tape = tapes[i], tapes[i - 1]
            idx %= cur_tape.pattern_len
            if idx >= prev_tape.total_len:
                if prev_tape.total_len:
                    idx = idx % prev_tape.total_len
                return cur_tape.last_word[idx]

    def add_tape(self, tapes: list[Tape], word: str, c: str | int):
        pattern_len = tapes[-1].total_len + len(word)
        total_len = pattern_len * int(c)
        tape = self.Tape(word, pattern_len, total_len)
        tapes.append(tape)

    def decodeAtIndex(self, s: str, k: int) -> str:
        tapes = [self.Tape("", 0, 0)]
        word = ""
        for c in s:
            if c.isalpha():
                word += c
            else:
                self.add_tape(tapes, word, c)
                word = ""
        if word:
            self.add_tape(tapes, word, 1)

        return self.solve(tapes, k - 1)
