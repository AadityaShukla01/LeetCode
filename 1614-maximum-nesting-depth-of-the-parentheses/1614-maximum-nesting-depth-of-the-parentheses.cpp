class Solution {
public:
    int maxDepth(string s) {
        int left=0;
        // int right=0;
        int ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else if(s[i]==')') left--;
            ans=max(ans,left);
        }
        return ans;
    }
};