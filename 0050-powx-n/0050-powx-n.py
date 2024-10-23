class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1
        sign = n >= 0
        n = abs(n)

        while n > 0:
            if n % 2:
                ans = ans * x
                n -= 1
            else:
                x = x*x
                n = n / 2

        if sign == False:
            return 1 / ans

        return ans