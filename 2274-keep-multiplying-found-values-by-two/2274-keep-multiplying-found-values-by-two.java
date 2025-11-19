class Solution {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer>set = new HashSet<>();
        for(int el: nums) set.add(el);

        while(set.contains(original)){
            original = original * 2;
        }
        return original;
    }
}