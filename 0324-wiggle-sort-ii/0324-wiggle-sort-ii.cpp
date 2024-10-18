class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>a(5001, 0);
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            a[nums[i]]++;
        }

        int j = 1;
        int i = 5000; 
        while(i >= 0)
        {
            int f = a[i];

            while(f > 0 && j < n)
            {
                nums[j] = i;
                j += 2;
                f--;
            }
            a[i] = f;
            i--;
        }
        i = 5000; 
        j = 0;
        while(i >= 0)
        {
            int f = a[i];

            while(f > 0 && j < n)
            {
                nums[j] = i;
                j += 2;
                f--;
            }
            a[i] = f;
            i--;
        }
    }
};