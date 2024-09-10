class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)

        @cache
        def lcs(i, j):
            if i >= n or j >= m:
                return 0

            ans = 0

            if s[i] == t[j]:
                ans = lcs(i + 1, j + 1) + 1

            else:
                ans = max(ans, lcs(i + 1, j), lcs(i, j + 1))

            return ans

        return lcs(0, 0)