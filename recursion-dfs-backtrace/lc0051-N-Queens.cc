class Solution {
public:
    vector<vector<sting>> solveNQueens(int n) {
        vector<vector<sting>> res;
        vector<string> queens(n, string(n, '.'));
        backtrace(queens, 0, res);
        return res;
    }

    void backtrace(vector<string>& queens, int row, vector<vector<string>>& res) {
        if (row == queens.size()) {
            res.push_back(queens);
        } else {
            for (int col = 0; col < queens.size(); col++) {
                if (isValid(queens, row, col)) {
                    queens[row][col] = 'Q';
                    backtrace(queens, row+1, res);
                    queens[row][col] = '.';
                }
            }
        }
    }

    bool isValid(vector<string>& queens, int row, int col) {
        for (int i = 0; i < row; i++)
            if (queens[i][col] == 'Q') return false;

        for (int i = row-1, j = col-1; i >=0 && j >= 0; --i, --j)
            if (queens[i][j] == 'Q') return false;

        for (int i = row-1, j = col+1; i >= 0 && j < queens.size(); --i, ++j)
            if (queens[i][j] == 'Q') return false;

        return true;
    }
};
