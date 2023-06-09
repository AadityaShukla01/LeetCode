class Solution {
public:
    int findTheWinner(int n, int k) {
       queue<int>q;
       for(int i=1;i<=n;i++)
            q.push(i);
        while(q.size()>1){
            int n = k-1;
            while(n--){
                int a = q.front();
                q.push(a);
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};