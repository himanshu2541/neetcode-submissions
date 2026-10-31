class Solution {
   public:
    void solve(int i, string& digits, string temp, vector<string>& ans, vector<string>& mapping) {
        if (i == digits.length()) {
            ans.push_back(temp);
            return;
        }

        string letters = mapping[digits[i] - '0'];

        for (auto ch : letters) {
            temp.push_back(ch);
            solve(i + 1, digits, temp, ans, mapping);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) return ans;

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0, digits, "", ans, mapping);

        return ans;
    }
};
