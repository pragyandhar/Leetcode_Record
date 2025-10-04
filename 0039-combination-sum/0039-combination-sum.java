class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int index, int target, int[] candidates, List<Integer> curr) {
        if (target == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (index == candidates.length) return;
        if (target >= candidates[index]) {
            curr.add(candidates[index]);
            helper(index, target - candidates[index], candidates, curr);
            curr.remove(curr.size() - 1);
        }
        helper(index + 1, target, candidates, curr);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        helper(0, target, candidates, new ArrayList<>());
        return ans;
    }
}