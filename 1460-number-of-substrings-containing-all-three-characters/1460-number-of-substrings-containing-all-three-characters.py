class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        bad = 0
        total = n * (n + 1) // 2
        j = 0

        def default_value():
            return 0
            
        mp = defaultdict(default_value)

        for i in range(n):
            if s[i] in mp:
                mp[s[i]] += 1
            else:
                mp[s[i]] = 1
            
            if mp['a'] > 0 and mp['b'] > 0 and mp['c'] > 0:
                while mp['a'] > 0 and mp['b'] > 0 and mp['c'] > 0:
                    mp[s[j]]-=1
                    j+=1

            bad += (i - j + 1)

        return total - bad