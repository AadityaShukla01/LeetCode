class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        stack<vector<string>>st;

        for(auto f: folder)
        {
            stringstream s(f);
            string str;
            vector<string>v1;
            while(getline(s, str, '/'))
            {
                
                v1.push_back(str);
                v1.push_back(",");
            }

            if(st.empty() == false)
            {
                vector<string>v2 = st.top();

                int i = 0;
                int j = 0;
                while(i < v1.size() && j < v2.size())
                {
                    if(v1[i] == v2[j]){
                        i++;
                        j++;
                    }
                    else break;
                }
                if(j == v2.size()) continue;
                st.push(v1);
            }
            else
            {
                st.push(v1);
            }
        }
        vector<string>ans;
        while(st.empty() == false)
        {
            vector<string>v = st.top();
            string temp = "";
            for(int i=0; i<v.size(); i++)
            {
                if(i == v.size() - 1) continue;
                if(v[i] == ",") temp += "/";
                else temp += v[i];
            }
            ans.push_back(temp);
            st.pop();
        }
        return ans;
    }
};