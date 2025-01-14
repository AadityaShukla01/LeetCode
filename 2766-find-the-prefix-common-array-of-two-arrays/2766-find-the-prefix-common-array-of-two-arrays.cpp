class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int>a, b, c;
        int n = A.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            a.insert(A[i]);
            b.insert(B[i]);
            c.insert(A[i]);
            c.insert(B[i]);

            ans[i] = (a.size() + b.size()) - c.size();
        }
        return ans;
    }
};