class Solution {
public:
//time complexity will be O(N*N*L) l because of the compare function l is the longest length of any string we have
    bool compare(string &s1,string &s2){
        int i=0;
        int j=0;
        int siz=s1.size()-s2.size();
        if(abs(siz)!=1)
        return false;

        while(j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==s1.size() && j==s2.size())
        return true;

        return false;
    }
    int sol(vector<string>& words,int n){
        vector<int>list(n);
        list[0]=1;
        for(int i=1;i<n;i++){
            list[i]=1;
            for(int j=0;j<i;j++){
                if(compare(words[j],words[i]) && list[i]<list[j]+1)
                list[i]=list[j]+1;
            }
        }
        int ans=*max_element(list.begin(),list.end());
        return ans;
    }
    static bool comp(string s1,string s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        return sol(words,n);
    }
};