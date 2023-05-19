class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_map<int,int>map;
        for(int i : target)
            map[i]++;
            
        vector<string>ans;
        vector<int>comp;

        for(int i=1 ;i<=n;i++){
            if(map.find(i) != map.end()){
                ans.push_back("Push");
                comp.push_back(i);
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(comp==target)
                return ans;
        }
        return ans;
    }
};