class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    continue;
                } else if (sum > 0){
                    r--;
                }   else{
                    l++;
                }
            }
        }

        vector<vector<int>> ans_vector(ans.begin(), ans.end());
        return ans_vector; 
    }
};
