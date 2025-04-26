class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        string mx = "~";
        map<string, int>mp;
        int mxF = 0;
        for(auto response: responses){
            map<string, int>temp;
            for(auto r: response){
                if(temp.find(r) == temp.end()){
                    mp[r]++;
                    temp[r]++;

                    if(mxF == mp[r]){
                        mx = min(mx, r);
                    }
                    else if(mxF < mp[r]){
                        mx = r;
                        mxF = mp[r];
                    }
                }
            }
        }
        return mx;
    }
};