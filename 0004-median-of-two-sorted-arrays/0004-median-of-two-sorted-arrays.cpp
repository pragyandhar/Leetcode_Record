class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(begin(nums1), end(nums1));
        double median = 0;
        if (nums1.size() % 2 == 0) {
            median = (double) (nums1[(nums1.size()/2) - 1] + nums1[nums1.size()/2])/2;
        } else {
            median = (double) nums1[nums1.size()/2];
        }
        return median;
    }
};