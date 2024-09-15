class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();

        // aaabbb
        // 10 00 10 11 10 11
        long long cnt = 0;
        unordered_map<int, int> map;

        int mask = 0;
        map[0] = 1;
        for (int i = 0; i < n; i++) {
            mask ^= (1 << (word[i] - 'a'));

            if (map.find(mask) != map.end())
                cnt += map[mask];

            for (int j = 0; j < 10; j++) {
                int newMask = mask ^ (1 << j);

                if (map.find(newMask) != map.end())
                    cnt += map[newMask];
            }
            map[mask]++;
        }
        return cnt;
    }
};