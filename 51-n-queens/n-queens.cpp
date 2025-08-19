class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<bool> visitedCol(n, false);
        vector<vector<vector<bool>>> res;
        vector<bool> rightDiag(2 * n, false);
        vector<bool> leftDiag(2 * n, false);
        backtrack(n, 0, board, visitedCol, res, rightDiag, leftDiag);
        vector<vector<string>> result;
        for (const auto& b : res) {
            vector<string> temp;
            for (const auto& row : b) {
                string s;
                for (bool cell : row) {
                    s += cell ? 'Q' : '.';
                }
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }

    void backtrack(int n, int row, vector<vector<bool>>& board,
                   vector<bool>& visitedCol, vector<vector<vector<bool>>>& res,
                   vector<bool>& rightDiag, vector<bool>& leftDiag) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!visitedCol[col] && !rightDiag[row + col] &&
                !leftDiag[n + row - col]) {
                board[row][col] = true;
                visitedCol[col] = rightDiag[row + col] =
                    leftDiag[n + row - col] = true;
                backtrack(n, row + 1, board, visitedCol, res, rightDiag,
                          leftDiag);
                board[row][col] = false;
                visitedCol[col] = rightDiag[row + col] =
                    leftDiag[n + row - col] = false;
            }
        }
    }
};