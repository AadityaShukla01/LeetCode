class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans = 0;
        int i = 0;
        int n = pizzas.size();
        int cnt = n / 4;

        sort(pizzas.begin(), pizzas.end());

        int odd = cnt / 2;
        if(cnt % 2) odd++;
        int j = odd * 3; 
        while(odd--){ 
            ans += pizzas[n - i - 1];
            i++;           
        }

        int even = cnt / 2;
        priority_queue<int>pq;
        
        while(j <= (n - i - 1)) pq.push(pizzas[j++]);
        int temp = even;
        while(temp--)
        {
            int a = pq.top(); 
            pq.pop();
            int b = pq.top();  
            pq.pop();  

            ans += b;          
        }
        return ans;
    }
};