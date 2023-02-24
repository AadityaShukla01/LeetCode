class Solution {
public:
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>lis(nums.size(),1);
        vector<int>store(nums.size());
        int maxi=0;
        int lastIndex=0;
        for(int i=0;i<nums.size();i++){
            store[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && lis[i]<lis[j]+1){
                    lis[i]=lis[j]+1;
                    store[i]=j;
                }
            }
            if(lis[i]>maxi){
                maxi=lis[i];
                lastIndex=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(store[lastIndex]!=lastIndex){
            lastIndex=store[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(),temp.end());
        return temp;
    }
};