class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        ///we will do it by our sw method
        vector<int>pattern(26,0);
        vector<int>window(26,0);

        //always check the size before
        if(s1.size()>s2.size())
        return false;
        //create first window
        for(int i=0;i<s1.size();i++){
            pattern[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }

        if(pattern==window)
        return true;

        for(int i=s1.size();i<s2.size();i++){
            //last elemnt ko remove karo
            window[s2[i-s1.size()]-'a']--;
            window[s2[i]-'a']++;

            if(window==pattern)
            return true;
        }
        return false;

    }
};