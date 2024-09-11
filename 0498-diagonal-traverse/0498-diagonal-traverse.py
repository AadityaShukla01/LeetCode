class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:

        ans = []
        n = len(mat)
        m = len(mat[0])
        mp = defaultdict(lambda: [])

        for i in range(n):
            for j in range(m):
                mp[i + j].append(mat[i][j])

        for i in mp:
            temp = []
            for el in mp[i]:
                temp.append(el)

            if i % 2 == 0:
                temp.reverse()

            for el in temp:
                ans.append(el)

        return ans
