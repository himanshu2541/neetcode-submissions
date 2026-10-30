
class Solution {
   public:
    void generate(int n, int openCount, int closeCount, string s, vector<string>& ans) {
        if (closeCount > openCount) return;
        if (openCount > n || closeCount > n) return;

        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        s += "(";
        generate(n, openCount + 1, closeCount, s, ans);

        s.pop_back();

        s += ")";
        generate(n, openCount, closeCount + 1, s, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }
};