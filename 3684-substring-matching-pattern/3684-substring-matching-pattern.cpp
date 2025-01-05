class Solution {
public:
    bool sol(string &s, string p1, string p2)
    {
        int n = s.size();
        int m1 = p1.size();
        int m2 = p2.size();
        
        bool f1 = false, f2 = false;

        if(!m1) f1 = true;
        if(!m2) f2 = true;
        int t = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                string temp = s.substr(i, j - i + 1);
                if(!f1 && temp == p1) 
                {
                    f1 = true;
                    t = j;
                } 
                else if(f1 && temp == p2 && i > t) return true;
            }
        }
        return f1 && f2;
    }
    bool hasMatch(string s, string p) {
        int n = s.size(), m = p.size();
        for(int i=0; i<m; i++)
        {
            if(p[i] == '*')
            {
                string temp1 = p.substr(0, i);
                string temp2 = p.substr(i + 1, m);

                cout << temp1 << " " << temp2 << "\n";
                return sol(s, temp1, temp2);
            }
        }
        return false;
    }
};