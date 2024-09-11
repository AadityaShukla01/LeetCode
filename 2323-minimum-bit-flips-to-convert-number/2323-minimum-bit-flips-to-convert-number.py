class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        count = 0

        for i in range(32):
            bit1 = start & (1 << i)
            bit2 = goal & (1 << i)

            if bit1 != bit2:
                count += 1

        return count
