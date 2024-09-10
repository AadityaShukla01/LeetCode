class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()

        for x in nums:
            s.add(x)

        mx = 0
        for x in nums:
            curr_len = 0
            curr = x
            if x + 1 not in s:
                while curr in s:
                    curr -= 1
                    curr_len += 1
                    mx = max(curr_len, mx)

        return mx
