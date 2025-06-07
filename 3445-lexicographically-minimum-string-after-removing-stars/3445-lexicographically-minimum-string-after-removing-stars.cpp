
class myComp {
public:
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        if (a.first > b.first)
            return true;
        else if (a.first == b.first) {
            if (a.second < b.second) {
                return true;
            }

            return false;
        }
        return false;
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> pq;
        int n = s.size();
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    int idx = pq.top().second;
                    pq.pop();
                    mark[idx] = 1;
                    mark[i] = 1;
                }
            } else {
                pq.push({s[i], i});
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!mark[i])
                ans += s[i];
        }
        return ans;
    }
};