class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int index, int n, int k, List<Integer> curr) {
        if (k == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (n - index + 1 < k) return;
        for (int i = index; i <= n; i++) {
            curr.add(i);
            helper(i+1, n, k-1, curr);
            curr.remove(curr.size() - 1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        helper(1, n, k, new ArrayList<>());
        return ans;
    }
}