class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrace(board, 0, 0);
    }

    bool backtrace(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // 终止条件
        if (col == 9) {
            return backtrace(board, row + 1, 0);
        }

        if (board[row][col] != '.') {
            return backtrace(board, row, col + 1);
        } else {
            for (int num = '1'; num <= '9'; num++) {
                if (isSafe(board, row, col, num) == false) continue;
                board[row][col] = num;
                if (backtrace(board, row, col + 1)) return true; // 找到了直接退出
                board[row][col] = '.';
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, int num) {
        for (int j = 0; j < 9; j++)
            if (board[row][j] == num) return false;

        for (int i = 0; i < 9; i++)
            if (board[i][col] == num) return false;
     
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] == num) return false;
     
        return true;
    }
};
