class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        set<int>set;

        for(auto el: nums){
            sum += el;
            set.insert(el);
        }

        int avg = sum / n;
        avg++;

        avg = max(avg, 1);
        while(set.find(avg) != set.end()){
            avg++;            
        }
        return max(1, avg);
    }
};