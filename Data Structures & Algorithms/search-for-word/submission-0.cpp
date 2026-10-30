class Solution {
   public:
    bool solve(int i, int j, int k, int n, int m, vector<vector<char>>& board, string word) {
        // base conditions
        if (k == word.size()) return true;
        // out of bound or character doesn't match
        if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] == '.' || board[i][j] != word[k])
            return false;

        // mark visited
        int ch = board[i][j];
        board[i][j] = '.';

        bool found = false;
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        for (auto& d : dirs) {
            int nr = i + d.first;
            int nc = j + d.second;

            found = found || solve(nr, nc, k + 1, n, m, board, word);
        }

        // backtrack
        board[i][j] = ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, 0, n, m, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
