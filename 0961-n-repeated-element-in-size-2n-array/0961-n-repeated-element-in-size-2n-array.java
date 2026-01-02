class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length;
        int limit = n / 2;
        Map<Integer, Integer>mp = new HashMap<>();   

        for(int el: nums){
            int f = mp.getOrDefault(el, 0);
            if(f + 1 == limit) return el;

            mp.put(el, f + 1);
        }

        return -1;
    }
}