class myComp {
public:
    int getSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    bool operator()(const int a, const int b) {
        int sum1 = 0, sum2 = 0;
        sum1 = getSum(a);
        sum2 = getSum(b);
        if (sum1 == sum2) {
            return a > b;
        } else if (sum1 < sum2) {
            return false;
        } else
            return true;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, myComp> pq;
        for (auto el : nums)
            pq.push(el);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;

        int i = 0;
        int cnt = 0;
        while (pq.empty() == false) {
            int el = pq.top();
            int idx = mp[el];
            pq.pop();
            if (i == idx) {
                i++;
            } else {                
                mp[nums[i]] = idx;
                mp[nums[idx]] = i;
                swap(nums[i], nums[idx]);
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};