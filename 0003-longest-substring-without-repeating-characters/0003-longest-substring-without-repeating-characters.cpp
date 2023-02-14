class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>q;
        int ans=0;
        int j=0;
        int i=0;
        while(i<s.size() && j<s.size()){
            if(q.find(s[i])==q.end()){
                q.insert(s[i]);
                i++;
                ans=max(ans,(i-j));
            }
            else{
                q.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
    
};