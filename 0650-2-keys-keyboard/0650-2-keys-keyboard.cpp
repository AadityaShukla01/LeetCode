#define vi vector<int>
#define vvi vector<vi>
#define INF 1'000'000
class Solution {
public:
    int count( int i, int n, int l, vvi& dp ){
        if(i>n) return 1e7;
        if(i==n) return 0;
        int copy= 2+count(2*i,n,i,dp);
        int paste=1+count(i+l,n,l,dp);

        return min(copy,paste);
       
    }
    int minSteps(int n) {
        vvi dp(n+1,vi(n+1,0));
        if(n==1)
        return 0;
        return count(1,n,1,dp)+1;
    }
};