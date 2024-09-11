class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        lo = 0
        hi = num
        ans = 0
        while lo <= hi:
            mi = lo + (hi - lo) // 2

            if mi * mi >= num:
                ans = mi
                hi = mi - 1
            else:
                lo = mi + 1

        return ans * ans == num


