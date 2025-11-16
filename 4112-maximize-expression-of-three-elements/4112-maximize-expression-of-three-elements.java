class Solution {
    public int maximizeExpressionOfThree(int[] nums) {
        int n = nums.length;
        int a = Integer.MIN_VALUE, b = Integer.MIN_VALUE, c = Integer.MAX_VALUE;

        for(int i=0; i<n; i++){
            if(nums[i] > a){
                b = a;
                a = nums[i];
            }
            else{
                b = Math.max(nums[i], b);
            }
            
            c = Math.min(c, nums[i]);
        }
        return a + b - c;
    }
}