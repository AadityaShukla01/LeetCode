class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // merge intervals;

        sort(meetings.begin(), meetings.end());

        vector<vector<int>>newMeetings;

        int i = 0;
        int n = meetings.size();

        while(i < n){
            int st = meetings[i][0];
            int en = meetings[i][1];

            while(i < n && en >= meetings[i][0])
            {
                en = max(en, meetings[i][1]);
                i++;
            }

            newMeetings.push_back({st, en});
        }

        int count = 0;
        
        for(int i=0; i<newMeetings.size() - 1; i++)
        {
            count += (newMeetings[i + 1][0] - newMeetings[i][1] - 1);
        }

        // edge cases 
        if(newMeetings[newMeetings.size() - 1][1] < days) 
            count += days - newMeetings[newMeetings.size() - 1][1];
        if(newMeetings[0][0] > 1) 
            count += newMeetings[0][0] - 1;    
        return count;
    }
};