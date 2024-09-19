class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1]*(amount + 1) for i in range(0, n)]
        def sol(i, n, coins, amount):
            if i == n:
                if amount == 0:
                    return 0
                return float('inf')

            if dp[i][amount] != -1:
                return dp[i][amount]

            ans = float('inf')
            if amount >= coins[i]:
                pick = sol(i, n, coins, amount - coins[i]) + 1
                ans = min(ans, pick)

            notPick = sol(i + 1, n, coins, amount)

            ans = min(ans, notPick)

            dp[i][amount] = ans

            return dp[i][amount]

        res = sol(0, n, coins, amount)
        if res == float('inf'):
            return -1

        return res