class Solution {
public:

    bool isSafe(int r, int c, int n, vector<string> &board){
        // horizontal
        for(int j = 0; j < n; j++){
            if(board[r][j] == 'Q'){
                return false;
            }
        }

        // vertical
        for(int i = 0; i < n; i++){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        // upper left diagonal
        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // upper right diagonal
        for(int i = r-1, j = c+1; i>=0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // lower left diagonal
        for(int i = r+1, j = c-1; i < n && j >= 0; i++, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // lower right diagonal
        for(int i = r+1, j=c+1; i < n && j < n; i++, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int r, int n, vector<string> &board, vector<vector<string>> &ans){
        if(r >= n) {
            ans.push_back(board);
            return;
        }

        
        for(int c = 0; c < n; c++){
            if(isSafe(r, c, n, board)){
                board[r][c] = 'Q';
                solve(r+1, n, board, ans);
            }
            board[r][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(0, n, board, ans);

        return ans;
    }
};
