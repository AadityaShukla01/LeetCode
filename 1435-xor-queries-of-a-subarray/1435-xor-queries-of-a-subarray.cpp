class Solution {
public:
    // vector<int>input;

    struct Q{
        int l, r, i;
    };
    vector<int> xorQueries(vector<int>& input, vector<vector<int>>& queries) {
        int n = input.size();
        int blockSize = ceil(sqrt(n));
        Q q[queries.size()];
        for(int i=0; i<queries.size(); i++){
            q[i].l = queries[i][0];
            q[i].r = queries[i][1];
            q[i].i = i;
        }

        sort(q, q + queries.size(), [blockSize = blockSize](Q q1, Q q2) {
            int b1 = q1.l / blockSize, b2 = q2.l / blockSize;
            return (b1 == b2) ? (q1.r < q2.r) : (b1 < b2);
        });
        int curr_l = 0;
        int curr_r = -1;
        vector<int>ans(queries.size());
        int curr_ans = 0;
        for(int i=0; i<queries.size(); i++){
            int l = q[i].l;
            int r = q[i].r;
            
            while(curr_l > l){
                curr_l--;
                curr_ans ^= input[curr_l];
            }

            while(curr_r < r){
                curr_r++;
                curr_ans ^= input[curr_r];
            }

            while(curr_l < l){
                curr_ans ^= input[curr_l];
                curr_l++;
            }

            while(curr_r > r){
                curr_ans ^= input[curr_r];
                curr_r--;
            }

            ans[q[i].i] = curr_ans;
        }
        return ans;
    }
};