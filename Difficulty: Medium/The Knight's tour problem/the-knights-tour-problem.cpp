class Solution {
  public:
    int dir[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    int countOptions(vector<vector<int>>& board, int x, int y) {
        int count = 0;
        int n = board.size();
    
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board[nx][ny] == -1) {
                count++;
            }
        }
        return count;
    }

    vector<vector<int>> getSortedMoves(vector<vector<int>>& board, int x, int y) {
        vector<vector<int>> moveList;
    
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
    
            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board.size() &&
                board[nx][ny] == -1) {
                int options = countOptions(board, nx, ny);
                moveList.push_back({options, i});
            }
        }
        sort(moveList.begin(), moveList.end());
    
        return moveList;
    }

    bool knightTourUtil(int x, int y, int step, int n, vector<vector<int>>& board) {
        if (step == n * n) return true;
    
        vector<vector<int>> moves = getSortedMoves(board, x, y);
    
        for (vector<int> move : moves) {
            int dirIdx = move[1];
            int nx = x + dir[dirIdx][0];
            int ny = y + dir[dirIdx][1];
    
            board[nx][ny] = step;
            if (knightTourUtil(nx, ny, step + 1, n, board))
                return true;

            board[nx][ny] = -1;
        }
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));

        board[0][0] = 0;
    
        if (knightTourUtil(0, 0, 1, n, board)) {
            return board;
        }
    
        return {{-1}};
    }
};