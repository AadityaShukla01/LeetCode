class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size();
        int idx = -1;

        for(int i=0; i<n-1; i++)
        {
            if(a[i] > a[i + 1])
            {
                idx = i;
                break;
            }
        }

        if(idx == -1) return true;
        int orig = a[idx];
        if(idx - 1 >= 0)
            a[idx] = a[idx - 1];
        bool c = true;
        for(int i=0; i<n-1; i++)
        {
            if(a[i] > a[i + 1]){
                c = false;
                break;
            }
        }
        if(c) return true;

        a[idx] = orig;
        c  = true;
        a[idx] = a[idx + 1];
        for(int i=0; i<n-1; i++)
        {
            if(a[i] > a[i + 1]){
                c = false;
                break;
            }
        }
        if(c) return true;

        a[idx] = orig;
        c  = true;
        a[idx + 1] = a[idx];
        for(int i=0; i<n-1; i++)
        {
            if(a[i] > a[i + 1]){
                c = false;
                break;
            }
        }
        if(c) return true;

        if(idx + 2 < n)
            a[idx + 1] = a[idx + 2];
        c  = true;
        for(int i=0; i<n-1; i++)
        {
            if(a[i] > a[i + 1]){
                c = false;
                break;
            }
        }
        return c;
    }
};