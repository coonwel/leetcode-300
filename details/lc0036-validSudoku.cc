class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool used[9];
        for (int i = 0; i < 9; i++) {
            std::fill(used, used + 9, false);
            for (int j = 0; j < 9; j++) {
                if (isValid(board[i][j], used) == false)
                    return false;
            }
           
            std::fill(used, used + 9, false);
            for (int j = 0; j < 9; j++) {
                if (isValid(board[j][i], used) == false)
                    return false;
            }

            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    std::fill(used, used + 9, false);
                    
                    for (int i = row*3; i < row*3 + 3; i++) {
                        for (int j = col*3; j < col*3 + 3; j++) {
                            if (isValid(board[i][j], used) == false)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    bool isValid(char ch, bool used[9]) {
        if (ch == '.') return true;
        if (used[ch - '1']) {
            return false;
        } else {
            used[ch - '1'] = true;
            return true;
        }
    }
};
