class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
         int res=0;
        
        vector<int>a2;
        vector<int>a1;
        for(int i=1;i<=n;i++){
            sum=sum+i;
            a1.push_back(sum);
        }
        
        for(int i=n;i>0;i--){
            res=res+i;
            a2.push_back(res);
        }
        
        reverse(a2.begin(),a2.end());
        for(int i=0;i<n;i++){
            if(a1[i]==a2[i])
                return i+1;
        }
        return -1;
    }
};