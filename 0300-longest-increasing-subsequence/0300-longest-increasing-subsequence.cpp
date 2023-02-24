class Solution
{
public:
    int sol(vector<int> ans, int n)
    {
        vector<int> list(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (ans[i] > ans[j] && list[i] < list[j] + 1)
                    list[i] = list[j] + 1;
            }
        }

        return *max_element(list.begin(), list.end());
    }

    int lengthOfLIS(vector<int> ans)
    {
        int n = ans.size();
        // Write your code here.
        // return sol(ans, n);
        vector<int>res;
        res.push_back(ans[0]);

        for(int i=1;i<n;i++){
            if(ans[i]>res.back()) res.push_back(ans[i]);
            else{
                //apply binary search to find appropriate place for this elemenet
                int index=lower_bound(res.begin(),res.end(),ans[i])-res.begin();
                res[index]=ans[i];
            }
        }
        return res.size();
    }
};