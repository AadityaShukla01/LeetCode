class Solution {
public:
    int sol(vector<vector<int>>& pairs,int n,int in ,int pre){
        if(in==n){
            return 0;
        }
        int pick=0,notPick=0;
        if(pairs[in][0]>pre){
            pick=1+sol(pairs,n,in+1,pairs[in][1]);
        }
        //case for not picking element
        notPick=sol(pairs,n,in+1,pre);

        return max(pick,notPick);
    }
    
    int tab(vector<vector<int>>& pairs,int n,int in){
        vector<int>list(n);
        list[0]=1;
        for(int i=1;i<n;i++){
            list[i]=1;
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0] && list[i]<list[j]+1){
                    list[i]=list[j]+1;
                }
            }
        }
        return *max_element(list.begin(),list.end());
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,-1);
        return tab(pairs,n,0);
    }
};