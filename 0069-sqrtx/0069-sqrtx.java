class Solution {
    public int mySqrt(int x) {
        return SquareRoot(x);
    }
    public int SquareRoot(int n){
        // return (int)(Math.pow(x,0.5)) ;  
        //kth root wale question me bas k --> 2     
        int lo = 1;
        int hi = n;
        int ans = 0;
        while (lo <= hi) {
            int mid = hi + (lo-hi)/2;
            if(Math.pow(mid,2) <= n) {
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return ans;
    }
}