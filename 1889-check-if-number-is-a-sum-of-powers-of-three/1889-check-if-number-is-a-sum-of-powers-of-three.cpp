class Solution {
public:
    // saw solution
    bool checkPowersOfThree(int n) {
        // we can represtn any number in 2's power because remainder is either 0 or 1

        // but for other numbers thats not the case

        // general solution
        // if remainder >= 2 we can never form the number using n
        while(n)
        {
            if(n == 1) return true;

            if(n % 3 >= 2) return false;

            n /= 3;
        }
        return true;
    }
};