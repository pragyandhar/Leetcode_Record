class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        SWD(0, new ArrayList<>(), ans, nums);
        return ans;
    }
    private void SWD(int indx, List<Integer> ds, List<List<Integer>> ans, int[] n) {
        ans.add(new ArrayList<>(ds));
        for(int i = indx; i < n.length; i++) {
            if (i > indx && n[i] == n[i-1]) continue;
            ds.add(n[i]);
            SWD(i+1, ds, ans, n);
            ds.remove(ds.size() - 1);
        }
    }
}