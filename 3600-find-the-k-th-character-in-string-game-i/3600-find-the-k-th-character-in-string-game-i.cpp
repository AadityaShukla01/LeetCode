class Solution {
public:
    char kthCharacter(int k) { 
        string curr = "a"; 

        while(curr.size() < k){
            string temp = curr;
            for(int i=0; i<curr.size(); i++){
                temp[i] = ((curr[i] + 1 - 'a') % 26) + 'a';
            }
            curr = curr + temp;
        }
        return curr[k - 1];
    }
};