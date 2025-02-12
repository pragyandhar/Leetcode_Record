class Solution {
    public int maxProfit(int[] prices) {
        int max=0,diff;
        for(int i=0;i<prices.length-1;i++){
            diff=prices[i+1]-prices[i];
            if(diff>0) max+=diff;
        }
        return max;  
    }
}