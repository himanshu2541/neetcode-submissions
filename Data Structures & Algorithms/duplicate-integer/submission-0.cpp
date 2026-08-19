class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        for(auto &[num, count]: freq){
            if(count > 1){
                return true;
            }
        }

        return false;
    }
};