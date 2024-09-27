class MyCalendarThree {
public:
    map<int, int>mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int s, int e) {
        int cnt = 0;
        mp[s]++;
        mp[e]--;
        int mx = 1;
        for(auto it: mp)
        {
            cnt += it.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */