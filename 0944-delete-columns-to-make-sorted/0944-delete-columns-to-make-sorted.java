class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int m = strs[0].length();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            char pre = 'z';
            for (int j = 0; j < n; j++) {
                if (j > 0 && strs[j].charAt(i) < pre) {
                    cnt++;
                    break;
                }
                pre = strs[j].charAt(i);
            }
        }
        return cnt;
    }
}