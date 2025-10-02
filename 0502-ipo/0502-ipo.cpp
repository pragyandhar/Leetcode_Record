class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // STEP-1: Pair the projects & sort by capital
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        // STEP-2: Initialise the maxHeap for profits of available projects
        priority_queue<int> maxHeap;
        int idx = 0;

        // STEP-3: Do it upto k-rounds
        for (int rounds = 0; rounds < k; rounds++) {
            while (idx < n && projects[idx].first <= w) {
                maxHeap.push(projects[idx].second);
                idx++;
            }

            // STEP-4: If the maxHeap is empty then break
            if (maxHeap.empty()) break;

            // STEP-5: Pick the top of the heap and add it to w & pop it from the heap
            w += maxHeap.top();
            maxHeap.pop();
        }
        // STEP-6: Return the requirements
        return w;
    }
};