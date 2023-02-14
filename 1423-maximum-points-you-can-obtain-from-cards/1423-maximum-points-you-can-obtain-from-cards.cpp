class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //subarrau with least sum of size n-k nikalo
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<cardPoints.size()-k;i++){
            sum=sum+cardPoints[i];
        }
        ans=min(ans,sum);

        for(int i=cardPoints.size()-k;i<cardPoints.size();i++){
            sum=sum-cardPoints[i-(cardPoints.size()-k)];
            sum=sum+cardPoints[i];

            ans=min(ans,sum);
        }
        sum=0;
        for(int i=0;i<cardPoints.size();i++)
            sum=sum+cardPoints[i];
        return sum-ans;
    }
};