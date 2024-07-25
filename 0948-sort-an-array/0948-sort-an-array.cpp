class Solution {
public:
    void divide(int l, int r, vector<int>&nums){
        if(l >= r) return;

        int mi = l + (r - l)/2;
        divide(l, mi, nums);
        divide(mi + 1, r, nums);
        conquer(l, mi, r, nums);
    }
    void conquer(int l, int mi, int r, vector<int>&nums){
        vector<int>temp;
        int i = l;
        int j = mi + 1;

        while(i <= mi && j <= r){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else 
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mi) 
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r) 
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int in=l; in<=r; in++){
            nums[in] = temp[in - l];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        divide(0, n - 1, nums);
        return nums;
    }
};