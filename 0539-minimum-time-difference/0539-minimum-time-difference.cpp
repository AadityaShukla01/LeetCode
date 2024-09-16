class Solution {
public:
    int getMinutes(string &time)
    {

        string hours = string(1, time[0]) + string(1, time[1]);

        int h = stoi(hours);

        string minutes = string (1, time[3]) + string(1, time[4]);

        int m = stoi(minutes);

        
        return h*60 + m;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>a;
        for(auto el: timePoints)
        {
            a.push_back(getMinutes(el));
        }
        
        sort(a.begin(), a.end());
        int mn = 1e9;

        for(int i=0; i<n-1; i++)
        {
           mn = min(mn, a[i + 1] - a[i]);
        }
        mn = min(mn, 1440 - (a[n - 1] - a[0]));
        return mn;
    }
};