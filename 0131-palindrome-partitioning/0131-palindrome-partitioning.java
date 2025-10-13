class Solution {
    List<List<String>> ans = new ArrayList<>();
    public boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) {
                return false;
            }
        }
        return true;
    }
    public void helper(int index, String s, List<String> curr) {
        int n = s.length();
        if (index == n) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)) {
                curr.add(s.substring(index, i+1));
                helper(i + 1, s, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        helper(0, s, new ArrayList<>());
        return ans;
    }
}