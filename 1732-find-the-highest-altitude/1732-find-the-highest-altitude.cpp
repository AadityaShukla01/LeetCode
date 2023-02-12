class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       for(int i=1;i<gain.size();i++){
           gain[i]=gain[i]+gain[i-1];
       }
        int a=*max_element(gain.begin(),gain.end());
        if(a>0)
        return a;
        
        return 0;
    }
};