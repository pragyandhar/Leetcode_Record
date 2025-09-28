/*
1. Initialise the unordered map with key as remainder and value as index
2. Process each element
     (i) Calculate the new prefix sum
    (ii) If the remainder before is seen or not
        (a) Not Seen: Store it
        (b) Seen: Distance between current and stored > 1 then true else false
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 1. Initialise the unordered map
        unordered_map<int, int> mp{{0,-1}};
        // 2. Process each element
        int runFixRem = 0;
        for (int i = 0; i < nums.size(); i++) {
            runFixRem = (runFixRem + nums[i]) % k;
            if (mp.find(runFixRem) == mp.end()) {
                mp.insert({runFixRem, i});
            } else if (i - mp[runFixRem] > 1) {
                return true;
            }
        }
        return false;
    }
};