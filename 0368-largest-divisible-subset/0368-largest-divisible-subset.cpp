class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>parent(n, 0), arr(n, 1);
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            for(int j=0; j<i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(arr[i] < arr[j] + 1)
                    {
                        parent[i] = j;
                        arr[i] = arr[j] + 1;
                    }
                }
            }
        }

        int lastIndex, mx = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > mx)
            {
                mx = arr[i];
                lastIndex = i;
            }
        }

        vector<int>ans;

        while(parent[lastIndex] != lastIndex)
        {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
              
        return ans;
    }
};