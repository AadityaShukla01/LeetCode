class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>res;
        unordered_map<int,int>map;
        for(int i=0;i<A.size();i++){
            int c=0;
            map[A[i]]++;
            map[B[i]]++;
            for(auto it:map){
                if(it.second==2) c++;
            }
            res.push_back(c);
        }
        return res;
    }
};