class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>a;
        while(n)
        {
            a.push_back(n % 10);
            n /= 10;
        }

        reverse(a.begin(), a.end());

        int bp = -1;

        for(int i=a.size()-2; i>=0; i--)
        {
            if(a[i] < a[i + 1])
            {
                bp = i;
                break;
            }
        }

        if(bp == -1) return -1;

        for(int j=a.size() - 1; j>bp; j--)
        {
            if(a[j] > a[bp])
            {
                swap(a[j], a[bp]);
                break;
            }
        }

        reverse(a.begin() + bp + 1, a.end());
        string res = "";
        long long ans = 0;
        int i = 0;
        while(i < a.size())
        {
            ans = ans * 10 + a[i];
            i++;
        }
        cout << INT_MAX;
        if(ans > INT_MAX) return -1;
        return ans;
    }
};