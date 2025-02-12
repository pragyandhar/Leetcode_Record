class Solution {
    public boolean canJump(int[] nums) {
        // Use a variable farthest to track the farthest index you can reach
        int farthest = 0;

        // Traverse the array
        for(int i = 0; i < nums.length; i++) {
            // If farthest is less than the current index, return false (you can't proceed further).
            if(i > farthest) return false;
            // At each index, check if you can update farthest
            farthest = Math.max(farthest, i + nums[i]);
        }
        
        // If the loop completes, the last index is reachable
        return true;
    }
}