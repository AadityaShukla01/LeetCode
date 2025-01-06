class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>res(n);
        for(int i=0; i<n; i++)
        {
            int ans = 0;
            for(int j=0; j<n; j++)
            {
                if(boxes[j] == '1')
                    ans += abs(i - j);
            }
            res[i] = ans;
        }

        return res;
    }
};