class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // store indices
        vector<int> ans;

        for(int i = 0; i < n; i++){
            
            // remove el outside of current window
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }

            // remove smaller el from back
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            // add current index
            dq.push_back(i);

            // window is complete
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
