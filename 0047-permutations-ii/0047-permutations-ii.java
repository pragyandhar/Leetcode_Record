/* METHOD-1: Used Array */
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void helper(int[] nums, boolean[] used, List<Integer> curr) {
        if (nums.length == curr.size()) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            curr.add(nums[i]);
            helper(nums, used, curr);
            curr.remove(curr.size() - 1);
            used[i] = false;
        } 
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        boolean[] used = new boolean[nums.length];
        Arrays.fill(used, false);
        helper(nums, used, new ArrayList<>());
        return ans;
    }
}
/* METHOD-2: Swap Based */
// class Solution {
//     public void Swap(int[] nums, int i, int j) {
//         int temp = nums[i];
//         nums[i] = nums[j];
//         nums[j] = temp;
//     }

//     public List<List<Integer>> permuteUnique(int[] nums) {
        
//     }
// }