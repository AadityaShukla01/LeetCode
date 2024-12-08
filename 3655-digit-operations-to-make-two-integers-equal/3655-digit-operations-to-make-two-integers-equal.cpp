class Solution {
public:
    typedef pair<int, int> P;
    vector<int> primes;

    void primeChk() {
        primes.resize(10001, 1);  // Initialize all numbers as prime
        primes[0] = primes[1] = 0;  // 0 and 1 are not prime
        int n = 10000;
        for (int i = 2; i * i < n; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }

    int minOperations(int n, int m) {
        primeChk(); 
        vector<int>dist(10001, 1e9);
        if(primes[n]) return -1;
        dist[n] = n;

        priority_queue<P, vector<P>, greater<P>>pq;

        pq.push({n, n});

        while(pq.empty() == false)
        {
            int num = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            string s = to_string(num);

            for(int i=0; i<s.size(); i++)
            {
                if(s[i] != '9')
                {
                    string temp = s;
                    temp[i] += 1;

                    int number = stoi(temp);

                    if(!primes[number] && dist[number] > wt + number)
                    {
                        dist[number] = wt + number;

                        pq.push({wt + number, number});
                    }
                }

                if(s[i] != '0')
                {
                    string temp = s;
                    temp[i] -= 1;

                    int number = stoi(temp);

                    if(!primes[number] && dist[number] > wt + number)
                    {
                        dist[number] = wt + number;

                        pq.push({wt + number, number});
                    }
                }
            }
        }
        if(dist[m] == 1e9) return -1;
        return dist[m];
    }
};
