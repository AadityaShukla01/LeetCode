class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = defaultdict(lambda: 0)
        n = len(nums)
        for i in range(n):
            if target - nums[i] in mp:
                return [i, mp[target - nums[i]]]

            mp[nums[i]] = i

        return [-1, -1]