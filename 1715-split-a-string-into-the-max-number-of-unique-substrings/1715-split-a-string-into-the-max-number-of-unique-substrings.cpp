class Solution {
public:
    int count;
    void sol(int i, int n, string s, set<string>&st){
        if(i >= n){
            int sz = st.size();
            count = max(sz, count);
            return;
        }

        for(int j=i;j<n; j++){
            string res =  s.substr(i, j-i+1);
            if(st.find(res) == st.end()){
                st.insert(res);
                sol(j+1, n, s, st);
                st.erase(res);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        int n = s.size();
        sol(0, n, s, st);
        return count ;
    }
};