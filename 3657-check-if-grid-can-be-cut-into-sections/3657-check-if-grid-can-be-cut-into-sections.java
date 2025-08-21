class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        List<int[]> rx = new ArrayList<>();
        List<int[]> ry = new ArrayList<>();
        for (int[] r : rectangles) {
            rx.add(new int[]{r[0], r[2]});
            ry.add(new int[]{r[1], r[3]});
        }
        return canInsert(rx) || canInsert(ry);
    }
    
    private boolean canInsert(List<int[]> intervals) {
        Collections.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(intervals.get(0)[1]);
        int partitions = 0;
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals.get(i)[0];
            int end = intervals.get(i)[1];
            while (!pq.isEmpty() && start >= pq.peek()) {
                pq.poll();
            }
            if (pq.isEmpty()) {
                partitions++;
            }
            pq.offer(end);
        }
        return partitions >= 2;
    }
}