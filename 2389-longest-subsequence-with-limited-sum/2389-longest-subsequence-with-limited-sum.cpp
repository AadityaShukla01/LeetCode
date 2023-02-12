class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        // vector<int>res;
        vector<int>ans;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            ans.push_back(sum);
        }
        int m=queries.size();
         vector<int> res(m,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[j] <= queries[i]) res[i] = j+1;          // wherever we got the max subsequence sum for i just update that
                else break;
            }
        }
        return res;
    }
};