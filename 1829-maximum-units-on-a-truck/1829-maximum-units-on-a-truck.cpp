class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort (boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;

        for (auto& b : boxTypes) {
            int boxes = b[0], units = b[1];
            int take = min(boxes, truckSize);
            totalUnits += take * units;
            truckSize -= take;

            if (truckSize == 0) break;
        }
        return totalUnits;
    }
};