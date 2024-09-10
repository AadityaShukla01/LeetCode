class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp1 = {}

        for c in s:
            if c in mp1:
                mp1[c] += 1
            else:
                mp1[c] = 1

        for c in t:
            mp1[c] = mp1.get(c, 0) - 1

        if len(s) != len(t):
            return False

        for c in mp1:
            if mp1.get(c) != 0:
                return False

        return True
