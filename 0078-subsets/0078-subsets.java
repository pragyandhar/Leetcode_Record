class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    private void helper(int index, int[] nums, List<Integer> path) {
        // BASE CASE
        if (index == nums.length) {
            ans.add(new ArrayList<>(path));
            return;
        }

        // Choice-1: Pick
        path.add(nums[index]);
        helper(index + 1, nums, path);

        // Choice-2: Skip
        path.remove(path.size() - 1);
        helper(index + 1, nums, path);
    }
    public List<List<Integer>> subsets(int[] nums) {
        helper(0, nums, new ArrayList<>());
        return ans;
    }
}