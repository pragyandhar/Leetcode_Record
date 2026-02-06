#include <bits/stdc++.h>
#define ll long long

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        ll a = 0;
        ll b = 0;
        for (int e:nums) {
            ans = max(ans, b*e);
            b = max(b, a-e);
            a = max(a, (ll) e);
        }
        return ans;
    }
};