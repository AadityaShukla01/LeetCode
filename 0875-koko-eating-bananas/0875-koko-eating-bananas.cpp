class Solution {
public:
    bool sol(vector<int>& piles, int t,int x){
        long long c=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] % x == 0)
                c+=piles[i]/x;
            else{
                c+=piles[i]/x;
                c++;
            }
        }
        if(c<=t) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long i=1;
        sort(piles.begin(),piles.end());
        long long j=piles[piles.size()-1];
        while(i<=j){
            int m=(i+j)/2;
            if(sol(piles,h,m))
                j=m-1;
            else
                i=m+1;
        }
        return j+1;
    }
};