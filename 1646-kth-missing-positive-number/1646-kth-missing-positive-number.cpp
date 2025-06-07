class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mi = lo + (hi - lo)/2;

            if(arr[mi] - (mi + 1) < k){
                lo = mi + 1;
            } else{
                hi = mi - 1;
            }
        }

        return  k + (hi + 1);
    }
};

// We can use binary search to find the index i such that the number of missing positive integers before index i is equal to k. If the number of missing positive integers before index i is less than k, we need to search the right half of the array. If the number of missing positive integers before index i is greater than or equal to k, we need to search the left half of the array.

// To find the number of missing positive integers before index i, we can use the formula arr[i] - i - 1, which represents the difference between the actual value of the element at index i and the expected value of the element at index i in a complete array of all positive integers.

// Once we find the index i, we can return the kth missing positive integer, which is equal to arr[i] + k - (arr[i] - i - 1).