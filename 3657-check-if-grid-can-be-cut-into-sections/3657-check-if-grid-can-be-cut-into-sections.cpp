class Solution {
public:
    static bool cmp1(const vector<int>&a, const vector<int>&b)
    {
        if(a[1] == b[1]) return a[3] < b[3];

        return a[1] < b[1];
    }

    static bool cmp2(const vector<int>&a, const vector<int>&b)
    {
        if(a[0] == b[0]) return a[2] < b[2];

        return a[0] < b[0];
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int cnt1 = 0;

        sort(rectangles.begin(), rectangles.end(), cmp1);
        int end = INT_MIN;
        for(int i=0; i<rectangles.size(); i++)
        {
            if(end != INT_MIN && rectangles[i][1] >= end)
            {
                cnt1++;
            }
            end = max(end, rectangles[i][3]);
        }
        int cnt2 = 0;
        sort(rectangles.begin(), rectangles.end(), cmp2);
        end = INT_MIN;
        for(int i=0; i<rectangles.size(); i++)
        {
            if(end != INT_MIN && rectangles[i][0] >= end)
            {
                cnt2++;
            }
            end = max(end, rectangles[i][2]);
        }
        return  max(cnt1, cnt2) >= 2;
    }
};