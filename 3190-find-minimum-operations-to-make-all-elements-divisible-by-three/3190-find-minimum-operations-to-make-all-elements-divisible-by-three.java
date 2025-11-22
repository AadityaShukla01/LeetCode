class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        int op = 0;
        for(int el: nums){
            if(el % 3 != 0) op++;
        }
        return op;
    }
}