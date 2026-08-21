class Solution {
   public:

    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<char>> rows(9), cols(9), boxes(9);

        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){

                if(board[r][c] == '.') continue;

                char val = board[r][c];

                // box - which box
                int box = (r / 3) * 3 + (c / 3);

                // check row
                if(rows[r].count(val)) return false;

                // check col
                if(cols[c].count(val)) return false;

                // check box
                if(boxes[box].count(val)) return false;

                // Mark as seen
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box].insert(val);

            }
        }

        return true;
    }
};
