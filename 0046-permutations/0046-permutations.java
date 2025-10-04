class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int[] nums, int[] used, List<Integer> curr) {
        if (nums.length == curr.size()) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i] == 1) continue;
            used[i] = 1;
            curr.add(nums[i]);
            helper(nums, used, curr);
            curr.remove(curr.size() - 1);
            used[i] = 0;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        int[] used = new int[nums.length];
        Arrays.fill(used, 0);
        List<Integer> curr = new ArrayList<>();
        helper(nums, used, curr);
        return ans;
    }
}