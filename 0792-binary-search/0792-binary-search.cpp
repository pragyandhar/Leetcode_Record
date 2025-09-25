class Solution {
public:
    // Helper
    int bs(vector<int>& a, int tar, int s, int e) {
        if (s <= e) {
            int mid = s + (e-s)/2;
            if (a[mid] == tar) return mid;
            else if (a[mid] <= tar) return bs(a, tar, mid + 1, e);
            else return bs(a, tar, s, mid - 1);
        }
        return -1;
    }

    int search(vector<int>& a, int t) {
        int st = 0, end = a.size()-1;
        return bs(a, t, st, end);
    }
};