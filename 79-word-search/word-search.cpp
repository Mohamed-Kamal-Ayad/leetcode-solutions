class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string word, int i,
                   vector<vector<bool>>& visited, int row, int col) {

        if (i == word.length()) {
            return true;
        }

        if (row < 0 || row >= board.size() || col < 0 ||
            col >= board.front().size() || board[row][col] != word[i] ||
            visited[row][col]) {
            return false;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int d = 0; d < 4; d++) {
            int newRow = row + dx[d];
            int newCol = col + dy[d];
            visited[row][col] = true;
            if (backtrack(board, word, i + 1, visited, newRow, newCol)) {
                return true;
            }
            visited[row][col] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.front().size(); j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, 0, visited, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};