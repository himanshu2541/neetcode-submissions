class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        unordered_map<int, int> freqCount;

        for (auto& num : nums) {
            freqCount[num]++;
        }

        for (auto& [num, freq] : freqCount) {
            bucket[freq].push_back(num);
        }

        vector<int> ans;

        for (int i = n; i > 0 && ans.size() < k; i--) {
            for (auto& el : bucket[i]) {
                if (ans.size() == k) break;

                ans.push_back(el);
            }
        }

        return ans;
    }
};
