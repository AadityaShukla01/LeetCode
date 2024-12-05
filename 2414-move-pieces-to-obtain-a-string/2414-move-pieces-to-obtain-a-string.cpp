class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++)
        {
            if(target[i] == 'L') cnt1++;
            if(start[i] == 'L') {
                if(cnt1) 
                {
                    cnt1--;
                    continue;
                }
                else return false;

            }
            if(start[i] == 'R') {
                if(cnt1) return false;
            }
        }
        if(cnt1) return false;
        for(int i=0; i<n; i++)
        {
            if(start[i] == 'L') start[i] = '_';
            if(target[i] == 'L') start[i] = 'L';
        }
        for(int i=n-1; i>=0; i--)
        {
            if(target[i] == 'R') cnt1++;
            if(start[i] == 'R') {
                if(cnt1) 
                {
                    cnt1--;
                    continue;
                }
                else return false;

            }
            if(start[i] == 'L') {
                if(cnt1) return false;
            }
        }
        if(cnt1) return false;
        return true;
    }
};