class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 0;
        int num = 10;
        while(n >= num)
        {
            n -= num;
            num--;
            cnt++;
        }

        if(cnt % 2) return true;
        return false;
    }
};