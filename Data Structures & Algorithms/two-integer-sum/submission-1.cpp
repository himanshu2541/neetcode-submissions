class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // complement -> index

    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(nums[i]) != mp.end()) {
            return {mp[nums[i]], i};
        }

        int diff = target - nums[i];
        mp[diff] = i;
    }

    return {};
}
};
