class Solution {
    public int numSub(String s) {
        int n = s.length();
        long ans = 0;
        int mo = 1000000007;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                long cnt = 0;
                while (i < n && s.charAt(i) == '1') {
                    cnt++;
                    i++;
                }
                ans += ((cnt) * (cnt + 1)) / 2;
            }
        }
        return (int)(ans % mo);
    }
}