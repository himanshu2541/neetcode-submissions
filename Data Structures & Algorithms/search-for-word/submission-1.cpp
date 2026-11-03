class Solution {
public:

    bool solve(int r, int c, int n, int m, vector<vector<char>> &board, int i, string word){
        if(i == word.size()) return true;
        // if out of bounds
        if(r < 0 || c < 0 || r >= n || c >= m){
            return false;
        }

        // if next char doesn't match
        if(board[r][c] != word[i]){
            return false;
        }

        // if already visited
        if(board[r][c] == '.'){
            return false;
        }


        // mark visited
        char ch = board[r][c];
        board[r][c] = '.';

        bool found = solve(r+1, c, n, m, board, i+1, word) ||
                    solve(r-1, c, n, m, board, i+1, word) ||
                    solve(r, c+1, n, m, board, i+1, word) ||
                    solve(r, c-1, n, m, board, i+1, word);

        board[r][c] = ch; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(solve(i, j, n, m, board, 0, word)){
                    return true;
                }
            }
        }

        return false;

    }
};
