class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n

        pro = 1

        for i in range(n):
            ans[i] *= pro
            pro = pro * nums[i]

        pro = 1

        for i in range(n - 1, -1, -1):
            ans[i] *= pro
            pro = pro * nums[i]

        return ans
