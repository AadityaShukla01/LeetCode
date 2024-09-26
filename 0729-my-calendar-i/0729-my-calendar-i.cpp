class MyCalendar {
public:
    vector<vector<int>>v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        int n = v.size();
        vector<vector<int>>temp;
        int i = -1;
        int l = 0;
        int r = n - 1;
        while(l <= r)
        {
            int mi = l + (r - l)/2;
            if(v[mi][1] <= start)
            {
                i = mi;
                l = mi + 1;
            }
            else r = mi - 1;
        }
        if(n == 0)
        {
            v.push_back({start, end});
            return true;
        }
        if(i == -1 && v[i + 1][0] < start) return false;
        if(i + 1 >= n)
        {
            v.push_back({start, end});
            return true;
        }
        if(v[i + 1][0] >= end)
        {
            v.insert(v.begin() + i + 1, {start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */