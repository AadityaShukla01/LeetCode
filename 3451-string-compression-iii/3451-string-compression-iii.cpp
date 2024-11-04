class Solution {
public:
    string compressedString(string w) {
        int n = w.size();

        string ans = "";
        
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            int j = i;

            while(j < n && w[i] == w[j])
            {
                j++;
                cnt++;
            }

            if(cnt > 9){
                while(cnt > 9)
                {
                    ans += to_string(9);
                    ans += w[i];
                    cnt -= 9;
                }
                if(cnt) 
                {
                    ans += to_string(cnt);
                    ans += w[i];
                }
            }
            else{
                ans += to_string(cnt);
                ans += w[i];
            }
            i = j - 1;
        }
        return ans;
    }
};