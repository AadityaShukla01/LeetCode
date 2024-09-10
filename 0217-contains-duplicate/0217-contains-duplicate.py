class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set()

        for el in nums:
            s.add(el)
        
        return len(s) != len(nums)
        