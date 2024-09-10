class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(lambda: 0)
        heap = []

        for x in nums:
            freq[x] += 1

        for f in freq:
            heapq.heappush(heap, (-1 * freq[f], f))

        ans = []
        i = 0
        while i < k:
            ans.append(heapq.heappop(heap)[1])
            i += 1

        return ans
