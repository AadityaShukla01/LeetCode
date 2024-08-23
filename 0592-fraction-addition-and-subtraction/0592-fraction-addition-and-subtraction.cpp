class Solution {
public:
    int lcm(vector<int>&a){
        int lcmm = a[0];

        for(int i=1; i<a.size(); i++){
            lcmm = (lcmm*a[i])/__gcd(lcmm, a[i]);
        }
        return lcmm;
    }
    string fractionAddition(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '/') cnt++;
        }
        vector<int>num(cnt), den(cnt);
        int j = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '/'){
                int nu = 0;
                int d = 0;

                if(i - 2 >= 0){
                    if(s[i - 2] == '1') nu = 10;
                }
                if(!nu){
                    nu = s[i - 1] - '0';
                }
                if(i + 2 < n && s[i + 2] == '0') d = 10;
                if(!d) d = s[i + 1] - '0';
                if(i - 2 >= 0){
                    if(s[i - 2] == '-') nu = -1*nu;
                    else if(nu == 10){
                        if(i - 3 >= 0 && s[i - 3] == '-') nu = -1*nu; 
                    }
                }
                num[j] = nu;

                den[j] = d;
                j++;
            }
        }

        int lcmm = lcm(den);
        int numerator = 0;
        for(int i=0; i<den.size(); i++){
            cout << num[i] << " ";
            numerator += (lcmm/den[i])*num[i];
        } 
        if(numerator == 0) return "0/1";
        // cout << numerator << " " << lcmm;
        int gcd = __gcd(abs(numerator), lcmm);
        if(gcd > 1){
            if(numerator < 0){
                string ans = to_string(numerator/gcd) + "/" + to_string(abs(lcmm/gcd));
                return ans;
            }
            else{
                string ans = to_string(1*numerator/gcd) + "/" + to_string(abs(lcmm/gcd));
                return ans;
            }
            
        }
        else{
            if(numerator < 0){
                string ans = to_string(numerator) + "/" + to_string(lcmm);
                return ans;
            }
            else{
                string ans = to_string(1*numerator) + "/" + to_string(lcmm);
                return ans;
            }
        }
        return "";
    }
};