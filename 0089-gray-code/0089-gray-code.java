class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ll = new ArrayList<>();
        int total = 1 << n;
        for(int i = 0; i < total; i++) {
            ll.add((i ^ (i >> 1)));
        }
        return ll;
    }
}