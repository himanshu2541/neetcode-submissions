class Solution {
public:
    void findAllSubsets(int i, vector<int> &nums, vector<int> &sub, vector<vector<int>> &ans){
        if(i == nums.size()) {
            ans.push_back(sub);
            return;
        }

        // c1: include element
        sub.push_back(nums[i]);
        findAllSubsets(i+1, nums, sub, ans);

        // backtrack - remove the element
        sub.pop_back();

        // c2: exclude element
        findAllSubsets(i+1, nums, sub, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;

        findAllSubsets(0, nums, sub, ans);

        return ans;
    }
};
