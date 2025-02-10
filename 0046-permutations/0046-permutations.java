class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Permutations(0, ans, nums);
        return ans;
    }
    private void Permutations(int indx, List<List<Integer>> ans,  int[] n) {
        if (indx == n.length) {
            List<Integer> ds = new ArrayList<>();
            for(int i = 0; i < n.length; i++) {
                ds.add(n[i]);
            }
            ans.add(new ArrayList<>(ds));
            return;
        }

        for(int i = indx; i < n.length; i++) {
            Swap(i, indx, n);
            Permutations(indx + 1, ans, n);
            Swap(i, indx, n);
        }
    }
    private void Swap(int start, int end, int[] a) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
    }
}