class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>set;
        for(auto el: bank) set.insert(el);
        queue<pair<string, int>>q;
        vector<char>options = {'A', 'C', 'G', 'T'};
        q.push({startGene, 0});

        while(q.empty() == false){
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(s == endGene) return steps;

            for(int i=0; i<options.size(); i++){
                for(int j=0; j<s.size(); j++){
                    char orig = s[j];

                    s[j] = options[i];

                    if(set.find(s) != set.end()){
                        set.erase(s);
                        q.push({s, steps + 1});
                    }

                    s[j] = orig;
                }
            }
        }
        return -1;
    }
};