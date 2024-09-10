class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(lambda: [])

        for x in strs:
            temp = ''.join(sorted(x))
            mp[temp].append(x)

        ans = []

        for x in mp:
            temp = []
            for s in mp[x]:
                temp.append(s)
            ans.append(temp)

        return ans