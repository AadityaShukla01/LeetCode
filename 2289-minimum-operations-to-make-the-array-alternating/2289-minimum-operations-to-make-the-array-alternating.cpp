class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int>odd, even;
        int n = nums.size();
        // if(n == 1) return 0;
        int o = 0, e = 0;
        for(int i=0; i<n; i++)
        {
            if(i % 2 == 0) 
            {
                e++;
                even[nums[i]]++;
            }
            else 
            {
                o++;
                odd[nums[i]]++;
            }
        }

        int fe_1 = 0, fe_2 = 0;
        int fo_1 = 0, fo_2 = 0;
        int o1 = 0, o2 = 0;
        int e1 = 0, e2 = 0;
        
        for(auto f: odd) {
            if(f.second > fo_1){
                fo_1 = f.second;
                o1 = f.first;
            }
        }
        for(auto f: odd) {
            if(f.first != o1 && f.second > fo_2){
                fo_2 = f.second;
                o2 = f.first;
            }
        }
        for(auto f: even) {
            if(f.second > fe_1){
                fe_1 = f.second;
                e1 = f.first;
            }
        }
        for(auto f: even) {
            if(f.first != e1 && f.second > fe_2){
                fe_2 = f.second;
                e2 = f.first;
            }
        }
        
        if(o1 != e1)
        {
            return (o - fo_1) + (e - fe_1);
        }
        else 
        {
            int op1 = (o - fo_1) + (e - fe_2);
            int op2 = (o - fo_2) + (e - fe_1);

            return min(op1, op2);
        }

        return 0; 
    }
};