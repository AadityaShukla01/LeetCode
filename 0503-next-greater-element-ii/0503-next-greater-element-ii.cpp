class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n = nums.size();
        int ans[2*n];
        nums.resize(2*n);
        
        for(int i=n; i<2*n; i++) //concatenate the same array
        {
            nums[i] = nums[i-n];
        }
        for(int i=2*n-1;i>=0;i--){
            if(s.size()==0)
            ans[i]=-1;

            else if(s.empty()==false && s.top()>nums[i])
            ans[i]=s.top();

            else if(s.empty()==false && s.top()<=nums[i]){
                while(s.empty()==false && s.top()<=nums[i]){
                    s.pop();
                }
                if(s.empty()==true)
                ans[i]=-1;
                else
                ans[i]=s.top();
            }
            s.push(nums[i]);
        }
         vector<int>v(ans, ans+n);
        // reverse(v.begin(),v.end());
        return v;
    }
};