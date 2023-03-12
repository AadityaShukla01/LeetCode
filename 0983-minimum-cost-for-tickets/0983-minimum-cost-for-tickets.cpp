class Solution {
public:
    int sol(vector<int>& input,int i,vector<int>& costs,vector<int>& map,vector<int>&dp){
        if(i>365) return 0; //we traversed for all days of a year

        if(map[i]!=true) return  sol(input,i+1,costs,map,dp); //if this day is not in our input please ingore it and search for next day
        if(dp[i]!=-1) return dp[i]; //memoisation 
        else{
            //we have 3 possibilities 1 day 7 day,30 day we chose the minimum plan
            int a=costs[0] + sol(input,i+1,costs,map,dp);
            int b=costs[1] +sol(input,i+7,costs,map,dp);
            int c=costs[2] +sol(input,i+30,costs,map,dp);

            return dp[i]=min(a,min(b,c));
        }
    }
    int mincostTickets(vector<int>& input, vector<int>& costs) {
        vector<int>map(366,false);
        vector<int>dp(366,-1);
        
        for(int i=0;i<input.size();i++){
            map[input[i]]=true;
        }
        return sol(input,0,costs,map,dp);
    }
};