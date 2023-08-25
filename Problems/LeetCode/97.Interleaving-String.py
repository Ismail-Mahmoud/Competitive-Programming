# https://leetcode.com/problems/interleaving-string/

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if(len(s1) + len(s2) != len(s3)):
            return False
        
        def dp(idx: list[int], string: list[str]):
            for k in range(2):
                if idx[k] == len(string[k]):
                    l = k ^ 1
                    return string[l][idx[l]:] == string[2][idx[2]:]
            
            if (idx[0], idx[1]) in mem:
                return mem[(idx[0], idx[1])]

            ret = False
            for k in range(2):
                if string[k][idx[k]] != string[2][idx[2]]:
                    continue
                new_idx = idx.copy()
                new_idx[k] += 1
                new_idx[2] += 1
                ret |= dp(new_idx, string)
            
            mem[(idx[0], idx[1])] = ret
            return ret

        mem = {}
        return dp([0, 0, 0], [s1, s2, s3])
