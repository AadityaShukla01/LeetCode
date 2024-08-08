class Solution {
public:
    long long sol(vector<int>&time, long long mi, int totalTrips){
        long long cnt = 0;
        for(auto el: time){
            cnt += mi/el;
            if(cnt >= totalTrips) return true;
        }

        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        long long lo = 1;
        long long hi = 1e16;
        long long ans = -1;
        while(lo <= hi){
            long long mi = lo + (hi - lo)/2;

            if(sol(time, mi, totalTrips)){
                ans = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return ans;
    }
};