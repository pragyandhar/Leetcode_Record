class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int n;
    private void helper(int index, int[] nums, List<Integer> curr) {
        n = nums.length;
        if (curr.size() >= 2) {
            ans.add(new ArrayList<>(curr));
        }
        HashSet<Integer> st = new HashSet<>();
        for (int i = index; i < n; i++) {
            if (!curr.isEmpty() && curr.get(curr.size() - 1) > nums[i]) continue;
            if (st.contains(nums[i])) continue;
            st.add(nums[i]);

            curr.add(nums[i]);
            helper(i+1, nums, curr);
            curr.remove(curr.size()-1);
        }
    }
    public List<List<Integer>> findSubsequences(int[] nums) {
        n = nums.length;
        helper(0, nums, new ArrayList<>());
        return ans;
    }
}