class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        Integer cand1 = null, cand2 = null;
        int cnt1 = 0, cnt2 = 0;

        // Phase 1: Voting
        for (int num: nums) {
            if (cand1 != null && num == cand1) {
                cnt1++;
            } else if (cand2 != null && num == cand2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cand1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Phase 2: Verification
        cnt1 = 0;
        cnt2 = 0;
        for (int num: nums) {
            if (num == cand1) cnt1++;
            else if (num == cand2) cnt2++;
        }

        List<Integer> res = new ArrayList<>();
        if (cnt1 > n/3) res.add(cand1);
        if (cnt2 > n/3) res.add(cand2);

        return res;
    }
}