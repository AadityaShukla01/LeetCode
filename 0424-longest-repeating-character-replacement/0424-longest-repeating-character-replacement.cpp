class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26]={0};
        int maxFreq=0;
        int i=0;
        int j=0;
        int ans=0;

        while(i<s.size() && j<s.size()){
            count[s[i]-'A']++;

            //storing the max Frequency of element in a window
            maxFreq=max(maxFreq,count[s[i]-'A']);

            //if remaianing length of window is less than k consider it
            if((i-j+1)-maxFreq<=k){
                //length ko store karliya
                ans=max(ans,(i-j+1));
            }
            else{
                count[s[j]-'A']--;
                j++; //winfow ko aage slide karo 
            }
            i++;
        }
        return ans;
    }
};