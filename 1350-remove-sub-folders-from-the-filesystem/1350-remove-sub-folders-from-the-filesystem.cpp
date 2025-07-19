class Solution {
public:
    bool isPrefix(string& a, string& b) {
        int n = min(a.size(), b.size());
        int i = 0, cnt = 0;
        while (i < n) {
            if (a[i] != b[i])
                break;
            i++;
            cnt++;
        }

        if (cnt == a.size()) {
            if (b.size() > cnt)
                return b[cnt] == '/';
            return true;
        }

        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int i = 0, j = 1;
        int n = folder.size();
        vector<int> vis(n, 0);
        sort(folder.begin(), folder.end());
        while (i < n && j < n) {
            if (isPrefix(folder[i], folder[j])) {
                vis[j] = 1;
                j++;
            } else {
                i++;
                j = max(j, i + 1);
            }
        }

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(folder[i]);
        }
        return ans;
    }
};