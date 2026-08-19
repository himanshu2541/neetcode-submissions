class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;

        for (auto& s : strs) {
            vector<int> count(26, 0);

            for (auto& c : s) {
                count[c - 'a']++;
            }

            mp[count].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }

        return ans;
    }
};
