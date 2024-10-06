class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);

        vector<string>v1, v2;

        string str;

        while(ss1 >> str)
        {
            v1.push_back(str);
        }

        while(ss2 >> str)
        {
            v2.push_back(str);
        }
        cout << v1.size() << " " << v2.size() << "\n";
        for(auto el: v1) cout << el << " ";
        cout << "\n";
        for(auto el: v2) cout << el << " ";
        cout << "\n";

        if(v1.size() > v2.size())
        {
            int i = 0, j = v1.size() - 1;
            int l = 0, r = v2.size() - 1;

            while(l <= r)
            {
                if(v2[l] == v1[i])
                {
                    i++;
                    l++;
                }

                else if(v2[r] == v1[j])
                {
                    r--;
                    j--;
                }
                else return false;
            }
        }
        else if(v2.size() > v1.size())
        {
            int i = 0, j = v2.size() - 1;
            int l = 0, r = v1.size() - 1;

            while(l <= r)
            {
                if(v1[l] == v2[i])
                {
                    i++;
                    l++;
                }

                else if(v1[r] == v2[j])
                {
                    r--;
                    j--;
                }
                else return false;
            }
        }
        else
        {
            int i = 0;
            while(i < v1.size())
            {
                if(v1[i] != v2[i]) return false;
                i++;
            }
        }
        return true;
    }
};