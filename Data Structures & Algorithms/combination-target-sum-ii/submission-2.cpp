class Solution {
public:
    void rec(int i, int target, vector<int> &nums, vector<int> &sub, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(sub);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            // skip duplicates in same recursion level
            if(j > i && nums[j] == nums[j-1]) continue;

            // since array is sorted
            if(nums[j] > target) break;

            sub.push_back(nums[j]);
            rec(j+1, target - nums[j], nums, sub, ans);

            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;

        rec(0, target, candidates, sub, ans);

        return ans;
    }
};
