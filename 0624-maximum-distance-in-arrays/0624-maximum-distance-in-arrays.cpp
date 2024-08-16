class Solution {
public:
    static bool comp1(const vector<int>&a, const vector<int>&b){
        int n = a.size();
        int m = b.size();

        if(a[n - 2] == b[m - 2]){
            return a[0] < b[0];
        }

        return a[n - 2] > b[m - 2];
    }
    static bool comp2(const vector<int>&a, const vector<int>&b){
        int n = a.size();
        int m = b.size();

        if(a[0] == b[0]){
            return a[n - 2] < b[m - 2];
        }

        return a[0] < b[0];
    }
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        for(int i=0; i<n; i++) arrays[i].push_back(i);
        vector<vector<int>> temp = arrays;
        sort(arrays.begin(), arrays.end(), comp1);
        sort(temp.begin(), temp.end(), comp2);
        // array
        // for(int i=0; i<n; i++){
        //     for(auto el: arrays[i])
        //         cout << el << " ";
        //     cout << "\n";
        // }
        // temp
        // for(int i=0; i<n; i++){
        //     for(auto el: temp[i])
        //         cout << el << " ";
        //     cout << "\n";
        // }
        int mx = arrays[0][arrays[0].size() - 2];
        int mn = temp[0][0];

        if(temp[0][temp[0].size() - 1] == arrays[0][arrays[0].size() - 1]){
            int mx2 =  arrays[1][arrays[1].size() - 2];
            int mn2 = temp[1][0];

            // cout << mx2 << " " << mn2 << "\n";

            return max(mx - mn2, mx2 - mn);
        }
        // cout << arrays[0] == temp[0] << "\n";
        return mx - mn;
    }
};