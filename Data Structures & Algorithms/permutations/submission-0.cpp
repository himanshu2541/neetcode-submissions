class Solution {
public:

    void findPermutations(int i, vector<int> &nums, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++ ){
            swap(nums[i], nums[j]);
            findPermutations(i+1, nums, ans);

            // backtrack
            swap(nums[i], nums[j]);
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        findPermutations(0, nums, ans);

        return ans;

    }
};
