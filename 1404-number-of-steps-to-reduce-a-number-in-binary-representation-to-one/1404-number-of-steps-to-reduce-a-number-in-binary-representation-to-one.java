class Solution {
    public int numSteps(String s) {
        int ans = 0;
        while (s.length() > 1) {
            int n = s.length();
            char ch = s.charAt(n-1);
            if (ch == '0') {
                s = s.substring(0, n-1);
                ans++;
            } else {
                int idx = 0;
                for (int i = n-1; i >= 0; i--) {
                    if (s.charAt(i) == '0') {
                        idx = i;
                        break;
                    }
                }
                if (idx == 0) {
                    s = '1' + "0".repeat(n);
                } else {
                    s = s.substring(0, idx) + '1' + "0".repeat(n-idx-1);
                }
                ans++;
            }
        }
        return ans;
    }
}