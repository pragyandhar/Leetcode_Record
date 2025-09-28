class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int i = 0;
        int j = 0;
        
        while(j < nums.size()){
            //calculation here
            while(dq.size() > 0 && dq.back() < nums[j]){
                dq.pop_back();
            }
            //insert dq
            dq.push_back(nums[j]);
            //window size < k Then j move 
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                //ans update
                if(!dq.empty()){
                    ans.push_back(dq.front());
                }
                //slide the window 
                if(dq.front() == nums[i]){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};