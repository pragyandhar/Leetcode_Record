class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int index, int target, int[] candidates, List<Integer> curr) {
        if (target == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (index == candidates.length) return;
        for (int i = index; i < candidates.length; i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            if (target >= candidates[i]) {
                curr.add(candidates[i]);
                helper(i+1, target - candidates[i], candidates, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        helper(0, target, candidates, new ArrayList<>());
        return ans;
    }
}