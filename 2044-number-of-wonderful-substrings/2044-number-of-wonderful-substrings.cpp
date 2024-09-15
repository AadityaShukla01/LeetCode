class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long cnt = 0;
        int mask = 0;
        map<int, int>mp;
        mp[0] = 1;
        for(int i=0; i<n; i++)
        {
            mask = mask ^ (1 << (word[i] - 'a'));

            // for even (0 odd)
            cnt += mp[mask];


            // for only one odd
            for(int j=0; j<=10; j++)
            {
                int newMask = mask ^ (1 << j);

                cnt += mp[newMask];
            }

            mp[mask]++;
        }
        return cnt;
    }
};