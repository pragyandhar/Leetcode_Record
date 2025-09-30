class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n-k;
        int total = accumulate(begin(cardPoints), end(cardPoints), 0);
        int sum = 0;
        int minSum = INT_MAX;
        if (windowSize == 0) return total;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand
            sum += cardPoints[right];
            // Check the window size
            if (right - left + 1 == windowSize) {
                minSum = min(sum, minSum);
                // Shrink
                sum -= cardPoints[left];
                left++;
            }
        }
        // Return the requirements
        return total - minSum;
    }
};