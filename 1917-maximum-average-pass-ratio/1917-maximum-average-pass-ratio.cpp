class Solution {
public:
    //took help
    // we want to maximise overall result
    // so we add 1 every time to that particular fraction which will bring us max delta
    // good question!
    typedef vector<double> P;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double ans = 0;

        priority_queue<P>pq;
        for(int i=0; i<n; i++)
        {
            int num = classes[i][0];
            int den = classes[i][1];

            double val = 1.0 * (num + 1) / (den + 1) - 1.0 * (num) / (den);

            // cout << val << "\n";
            pq.push({val, 1.0 * num, 1.0* den});
        }

        while(extraStudents--)
        {
            auto it = pq.top();
            pq.pop();

            int num = it[1];
            int den = it[2]; 
            num++;
            den++;     

            
            double val = 1.0 * (num + 1) / (den + 1) - 1.0 * (num) / (den);
            pq.push({val, 1.0 * num, 1.0* den});
        }

        while(pq.empty() == false){
            auto it = pq.top();
            pq.pop();

            ans += 1.0 * (it[1]) / (it[2]);
        }
        return 1.0 * ans/n;
    }
};