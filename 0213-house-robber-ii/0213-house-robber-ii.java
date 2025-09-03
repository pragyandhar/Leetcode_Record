class Solution {
    public int rob(int[] nums) {
        
        int len = nums.length;
        if(len ==1) return nums[0];
        int [] dpt = new int [len];
        int [] dpnt = new int [len];

        Arrays.fill(dpt,-1);
        Arrays.fill(dpnt,-1);

        int a = helper(len-1,dpt,nums,1);
        int b = helper(len-2,dpnt,nums,0);

        return Math.max(a,b);
    }


    public static int helper(int idx,int [] dp,int[] nums,int end){
        if(idx == end )return nums[idx];
        if(idx < end) return 0;

        if(dp[idx] != -1)return dp[idx];

        int taken = nums[idx]+helper(idx-2,dp,nums,end);
        int nottaken = helper(idx-1,dp,nums,end);

        dp[idx] = Math.max(taken,nottaken);
        return dp[idx];

    }
}