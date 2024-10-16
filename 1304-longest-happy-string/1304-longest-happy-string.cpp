class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a)
        pq.push({a, 'a'});
        if(b)
        pq.push({b, 'b'});
        if(c)
        pq.push({c, 'c'});

        string ans = "";
        while(pq.empty() == false)
        {
            auto it1 = pq.top();
            pq.pop();
            cout << it1.first << " " << it1.second << "\n";
            if(it1.first > 2)
            {
                ans += string(2, it1.second);
                if(pq.size() >  0)
                {
                    auto it2 = pq.top();
                    pq.pop();

                    if(it2.first >= 2)
                    {
                        if(it2.first - 1 >= it1.first - 2){
                            ans += string(2, it2.second);
                            pq.push({it2.first - 2, it2.second});
                        }
                        else{
                            ans += string(1, it2.second);
                            pq.push({it2.first - 1, it2.second});
                        }
                    }
                    else
                    {
                        ans += string(it2.first, it2.second);
                    }
                }
                else 
                    break;

                pq.push({it1.first - 2, it1.second});
            }
            else {
                ans += string(it1.first, it1.second);
            }
        }
        return ans;
    }
};