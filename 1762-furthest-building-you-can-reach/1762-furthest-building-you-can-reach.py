class Solution:
    def furthestBuilding(self, nums: List[int], bricks: int, ladders: int) -> int:
        heap = []
        sum = 0

        n = len(nums)

        for i in range(n - 1):
            if nums[i + 1] - nums[i] <= 0:
                continue

            diff = nums[i + 1] - nums[i]

            heapq.heappush(heap, -1*diff)

            sum += diff

            if sum > bricks:
                if ladders > 0:
                    sum -= -1*heapq.heappop(heap)
                    ladders-=1
                else:
                    return i
        return n - 1