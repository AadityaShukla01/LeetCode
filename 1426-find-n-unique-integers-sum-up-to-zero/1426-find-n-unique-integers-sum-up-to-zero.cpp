class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>a;
        int len = n; 
        while(n && a.size() + 2 <= len){
            a.push_back(n);
            a.push_back(-1 * n);
            n--;
        }

        if(a.size() < len) a.push_back(0);

        return a;
    }
};