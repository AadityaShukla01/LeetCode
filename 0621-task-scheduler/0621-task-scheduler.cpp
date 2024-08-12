class Solution {
public:
    // always place first the element with max frequency
    // now for remaing n places put all other characters & reduce their freq by 1
    // if pq is empty we just add the popped chars 
    // else we need another round and just add n
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>m(26, 0);
        for(auto c: tasks)
            m[c - 'A']++;

        priority_queue<int>pq;

        for(auto f: m){
            if(f) pq.push(f);
        }
        int time = 0;
        while(pq.empty() == false){
            auto el = pq.top();
            pq.pop();

            // for current character
            time++;
            
            int cnt = 0;
            vector<int>newF;
            while(pq.empty() == false && cnt < n){
                int freq = pq.top();
                pq.pop();
                newF.push_back(freq - 1);
                cnt++;
            }
            if(el - 1) pq.push(el - 1);
            for(auto c: newF){
                if(c > 0) pq.push(c);
            }

            // this was the last slot and we dont need another slot
            if(pq.empty()){
                time +=  newF.size();
            }
            // we need another slot
            else time += n;
        }

        return time;
    }
};
// FOR N = 2
// A -- | A -- | A--
// We made 3 slots