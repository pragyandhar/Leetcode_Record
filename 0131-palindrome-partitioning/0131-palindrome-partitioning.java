class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> part = new ArrayList<>();
        PalinPart(0, s, ans, part);
        return ans;
    }

    private void PalinPart(int indx, String s, List<List<String>> ans, List<String> part) {
        if (indx == s.length()) {
            ans.add(new ArrayList<>(part));
            return;
        }

        for (int i = indx; i < s.length(); i++) {
            if (isPalindrome (s, indx, i)) {
                part.add(s.substring(indx, i+1));
                PalinPart(i+1, s, ans, part);
                part.remove(part.size()-1);
            }
        }
    }
    
    private boolean isPalindrome(String s, int start, int end) {
            while(start <= end) {
                if (s.charAt(start++) != s.charAt(end--)) return false;
            }
            return true;
        }
}