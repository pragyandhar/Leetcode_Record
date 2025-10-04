class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int index, int k, int n, int[] arr, List<Integer> curr) {
        if (n == 0 && curr.size() == k) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (index == arr.length) return;
        for (int i = index; i < arr.length; i++) {
            if (i > index && arr[i] == arr[i-1]) continue;
            if (!curr.isEmpty() || n >= arr[i]) {
                curr.add(arr[i]);
                helper(i+1, k, n-arr[i], arr, curr);
                curr.remove(curr.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        int[] arr = new int[9];
        for (int i = 0; i < 9; i++) {
            arr[i] = i + 1;
        }
        helper(0, k, n, arr, new ArrayList<>());
        return ans;
    }
}