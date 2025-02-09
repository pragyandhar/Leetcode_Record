class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Subset(0, new ArrayList<>(), ans, nums);
        return ans;
    }
    private void Subset(int idx, List<Integer> ds, List<List<Integer>> ans, int[] n) {
        if (idx == n.length) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        ds.add(n[idx]);
        Subset(idx + 1, ds, ans, n);
        ds.remove(ds.size() - 1);
        Subset(idx + 1, ds, ans, n);
    }
}