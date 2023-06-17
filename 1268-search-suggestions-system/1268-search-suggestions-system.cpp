class Solution {
public:
    bool comp(string &s, string &p){
        int i=0;
        int j=0;
        while(s[i]==p[j] && j<p.size()){
            i++;
            j++;
        }
        return j==p.size();
    }
    vector<string> sol(vector<string>& product, string &p){
        // int i=0;
        int j=0;
        vector<string>ans;
        for(int i=0;i<product.size();i++){
            string it = product[i];
            if(comp(it,p))
                ans.push_back(it);
            if(ans.size()==3)
                break;
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        sort(products.begin(),products.end());
        vector<vector<string>>res;
        string temp = "";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            cout<<temp<<endl;
            vector<string>ans = sol(products,temp);
            res.push_back(ans);
        }
        return res;
    }
};