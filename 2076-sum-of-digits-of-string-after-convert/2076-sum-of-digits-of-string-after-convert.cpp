class Solution {
public:
    string sum(string t)
    {
        int sm = 0;
        for(int i=0; i<t.size(); i++){
            sm += (t[i] - '0');
        }
        return to_string(sm);
    }
    int getLucky(string s, int k) {
        string t = "";
        for(auto c: s){
            t += to_string(c - 'a' + 1);
        }
        // cout << t;
        while(k--)
        {
            t = sum(t);
        }
        // cout << t;
        return stoi(t);
    }
};