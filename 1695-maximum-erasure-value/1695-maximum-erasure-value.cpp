class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> set;
        int ans = 0;
        int j = 0;
        int sum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            while(set.find(nums[i])!=set.end()){
                sum=sum-nums[j];
                set.erase(nums[j]); //removing repeated element
                j++;
            }
            sum=sum+nums[i];
            set.insert(nums[i]);
            ans=max(sum,ans);
        }
        return ans;
    }
};