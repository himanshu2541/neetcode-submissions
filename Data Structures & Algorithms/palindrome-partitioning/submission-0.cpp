class Solution {
   public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int i, string s, vector<string>& temp,
               vector<vector<string>>& ans) {
        if (i == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j - i + 1));
                // process remaining string
                solve(j+1, s, temp, ans);

                // backtrack
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, s, temp, ans);

        return ans;
    }
};
