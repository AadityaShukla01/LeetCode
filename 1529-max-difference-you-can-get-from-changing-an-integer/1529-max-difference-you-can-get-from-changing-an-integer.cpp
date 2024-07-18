class Solution {
public:
    int maxDiff(int num) {
        string number = to_string(num);
        int n = number.size();
        string maxNum;
        for (char x = '0'; x <= '9'; x++) {   
            for(char y = '1'; y <='9'; y++){
                string temp = number;
                for(int i=0; i<n; i++){
                    if(temp[i] == x) temp[i] = y;
                }
                maxNum = max(maxNum, temp);
            }
        }
        string minNum = "~~~~~~~~~~~";
        for (char x = '1'; x <= '9'; x++) {   
            for(char y = '0'; y <='9'; y++){
                string temp = number;
                if(temp[0] == x && y == '0') continue;
                for(int i=0; i<n; i++){
                    if(temp[i] == x) temp[i] = y;
                }
                cout <<x <<" " << y << " " <<minNum << "\n";
                minNum = min(minNum, temp);
            }
        }
        // cout << maxNum << " " << minNum << "\n";
        return stoi(maxNum) - stoi(minNum);
    }
};