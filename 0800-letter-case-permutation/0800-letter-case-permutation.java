class Solution {
    List<String> ans = new ArrayList<>();
    public void helper (int index, StringBuilder s) {
        // BASE CASE
        if (index == s.length()) {
            ans.add(s.toString());
            return;
        }
        
        char ch = s.charAt(index);

        // RECURSION
        if (Character.isLetter(ch)) {
            // Lowercase branch
            s.setCharAt(index, Character.toLowerCase(ch));
            helper (index + 1, s);
            // Uppercase branch
            s.setCharAt(index, Character.toUpperCase(ch));
            helper(index + 1, s);
        } else {
            helper (index + 1, s);
        }
    }
    public List<String> letterCasePermutation(String s) {
        helper(0, new StringBuilder(s));
        return ans;
    }
}