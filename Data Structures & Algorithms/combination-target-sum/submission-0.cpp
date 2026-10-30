class Solution {
public:
    void rec(int i, vector<int> &nums, int target, vector<int> &comb, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(comb);
            return;
        }

        if(i == nums.size()) return;

        // include nums[i] if it does not exceed target
        if(nums[i] <= target){
            comb.push_back(nums[i]);

            rec(i, nums, target - nums[i], comb, ans);

            comb.pop_back();
        }

        // exclude nums[i] and move to next element 
        rec(i+1, nums, target, comb, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        rec(0, nums, target, comb, ans);

        return ans;
    }
};
