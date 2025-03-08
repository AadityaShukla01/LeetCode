class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        int n = blocks.size();

        for(int i=0; i<k; i++)
        {
            if(blocks[i] == 'W') white++;
        }

        int mn = INT_MAX;
        
        mn = min(mn, white);

        for(int i=k; i<n; i++){
            if(blocks[i] == 'W') white++;
            if(blocks[i - k] == 'W') white--;

            mn = min(mn, white);
        }
        return mn;
    }
};