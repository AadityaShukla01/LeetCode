class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0, n = chalk.size();
        long long sum = 0;
        for(auto el: chalk) sum += el;
        k = k % sum;

        while(true)
        {
            if(chalk[i % n] > k) return i % n;
            k -= chalk[i % n];
            i++;
        }
        return -1;
    }
};