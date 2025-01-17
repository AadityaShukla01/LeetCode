class Solution {
public:
    bool doesValidArrayExist(vector<int>& a) {       
        int num0 = 0;
        int n = a.size();
        if(n == 1 && !a[0]) return true; 
        if(n == 1 && a[0]) return false; 
        int curr = num0;
        for(int i=0; i<n-1; i++){
            if(a[i]) curr = !curr;
            else continue;
        } 
        if((curr ^ num0) == a[n - 1]) return true;
        num0 = 1;
        curr = num0;
        for(int i=0; i<n-1; i++){
            if(a[i]) curr = !curr;
            else continue;
        } 
        if((curr ^ num0) == a[n - 1]) return true;

        return false;
    }
};