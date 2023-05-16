class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char,int>map;
    for(int i=0;i<t.size();i++)
        map[t[i]]++;
    
    int c=t.size();
    int j=0;
    int i=0;
    int minLen=INT_MAX;
    int minStart=0;
    while(j<s.size()){

        if(map[s[j]] > 0)
            c--;

        map[s[j]]--;
        j++;
        
        while(c==0){
            if(j-i<minLen){
                minLen=j-i;
                minStart=i;
            }
            map[s[i]]++;

            if(map[s[i]] > 0)
                c++;
            i++;
        }
    }
        string res=s.substr(minStart,minLen);
        if(minLen != INT_MAX) return res;
        return "";
}
};