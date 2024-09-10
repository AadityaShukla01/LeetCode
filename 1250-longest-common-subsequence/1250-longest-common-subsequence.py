class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)

        dp = [[-1] * m for _ in range(n)]

        def lcs(i, j):
            if i >= n or j >= m:
                return 0

            if dp[i][j] != -1:
                return dp[i][j]

            ans = 0

            if s[i] == t[j]:
                ans = lcs(i + 1, j + 1) + 1

            else:
                ans = max(ans, lcs(i + 1, j), lcs(i, j + 1))

            dp[i][j] = ans
            return dp[i][j]

        return lcs(0, 0)
