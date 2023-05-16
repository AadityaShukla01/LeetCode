class Solution {
public:
   vector<int> findAnagrams(string s, string p) {
       vector<int>ans;
       if(p.size()>s.size()) return ans;
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        for(int i=0;i<p.size();i++)
            arr1[p[i]-'a']++;

        for(int i=0;i<p.size();i++)
            arr2[s[i]-'a']++;
            
        int j=0;
        if(arr1==arr2) ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            // if(arr1==arr2) ans.push_back(j);
            arr2[s[i]-'a']++;
            arr2[s[i-p.size()]-'a']--;
            // if(arr2[s[j]-'a']==0) arr2.erase(arr2[s[j]-'a']);
            if(arr1==arr2) ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};