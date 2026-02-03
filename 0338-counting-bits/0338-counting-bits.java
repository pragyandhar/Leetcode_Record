class Solution {
    public int set(int i) {
        int x = 0;
        while(i > 0){
            i = ( i & (i - 1));
            x++;
        }
        return x;
    }
    public int[] countBits(int n) {
        int arr[] = new int[n+1];
        for(int i = 0; i <= n;i++) {
            arr[i] = set(i);

        }
        return arr;
    }
}