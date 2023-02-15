class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> map;
        int ans = INT_MAX;
        int j = 0;
        for (int i = 0; i < cards.size(); i++)
        {
            //frequency store karo
            map[cards[i]]++;

            //agare frequency 2 ho jaye immediate length store karlo or window
            //ko update karlo
            if (map[cards[i]] == 2)
            {
                //jab tak frequency 2 wala element hat na jaye j ko aage badhao
                //or aage se elements hatao
                while (map[cards[i]] != 1)
                {
                    ans = min(ans, (i - j + 1));
                    map[cards[j]]--;
                    if (map[cards[j]] == 0)
                        map.erase(cards[j]);
                    j++;
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};