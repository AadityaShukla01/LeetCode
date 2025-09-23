class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>a, b;
        stringstream ss(version1);
        string str;

        while(getline(ss, str, '.')){
            a.push_back(str);
        }

        stringstream ss1(version2);
        

        while(getline(ss1, str, '.')){
            b.push_back(str);
        }

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(stoi(a[i]) < stoi(b[j])){
                return -1;
            }
            else if(stoi(a[i]) > stoi(b[j])) return 1;

            i++;
            j++;
        }

        if(i < a.size()){
            while(i < a.size()){
                if(stoi(a[i])) return 1;
                i++;
            }
        }

        if(j < b.size()){
            while(j < b.size()){
                if(stoi(b[j])) return -1;
                j++;
            }
        }

        return 0;
    }
};