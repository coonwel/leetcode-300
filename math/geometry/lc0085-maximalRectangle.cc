class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> Height(n, 0);
        vector<int> Left(n, 0);
        vector<int> Right(n, n);

        int res = 0;
        for (int i = 0; i <= m-1; i++) {
            int left = 0, right = n;
            for (int j = 0; j <= n-1; j++) {
                if (matrix[i][j] == '1') {
                    ++Height[j];
                    Left[j] = std::max(Left[j], left);
                } else {
                    left = j+1;
                    Height[j] = 0; Left[j] = 0; Right[j] = n;
                }
            }

            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    Right[j] = std::min(Right[j], right);
                    res = std::max(res, Height[j]*(Right[j] - Left[j]));
                } else {
                    right = j;
                }
            }
        }

        return res;
    }
};
