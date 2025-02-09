class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        findCombinations(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }

    private void findCombinations(int indx, int[] a, int t, List<List<Integer>> ans, List<Integer> ds) {
        if (t == 0) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        for (int i = indx; i < a.length; i++) {
            if (i > indx && a[i] == a[i-1]) continue;
            if (a[i] > t) break;

            ds.add(a[i]);
            findCombinations(i + 1, a, t - a[i], ans, ds);
            ds.remove(ds.size() - 1);
        }
    }
}