class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int sum = 0;
        for(int i=0; i<n-1; i++)
        {
            if(heights[i] >= heights[i + 1]) continue;
            
            int diff = heights[i + 1] - heights[i];

            pq.push(diff);
            sum += diff;
            if(sum > bricks)
            {
                if(ladders){
                    sum -= pq.top();
                    pq.pop();
                    ladders--;
                }
                else return i;
            }
        }
        return n - 1;
    }
};