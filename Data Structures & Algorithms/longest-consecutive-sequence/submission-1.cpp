class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        int length = 0;

        for(int i = 0; i < nums.size(); i++){
            // we will start the sequence, if num - 1 does not exist in set
            if(st.count(nums[i] - 1)) continue;
            
            int count = 0;
            while(st.count(nums[i]++)){
                count++;
            }
            length = max(length, count);
        }

        return length;

    }
};
