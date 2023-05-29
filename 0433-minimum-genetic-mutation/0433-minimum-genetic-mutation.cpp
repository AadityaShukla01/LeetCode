class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>set;
        for(auto it : bank)
            set.insert(it);

        set.erase(startGene);
        queue<pair<string,int>> q;
        q.push({startGene,0});

        while(q.empty() == false){
            string original = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(original == endGene)
                return steps;

            for(int i=0;i<original.size();i++){
                char c = original[i];
                for(char p='A';p<='Z';p++){

                    original[i]=p;

                    if(set.find(original) != set.end()){
                        q.push({original,steps+1});
                        set.erase(original);
                    }
                }
                original[i]=c;
            }
        }
        return -1;
    }
};