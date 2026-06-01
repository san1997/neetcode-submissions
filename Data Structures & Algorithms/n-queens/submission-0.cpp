class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        vector<vector<string>> ans;

        dfs(0, board, ans);

        return ans;

    }

    void dfs(int i, vector<string>& board, vector<vector<string>>& ans) {
        if (i == board.size()) {
            ans.push_back(board);
            return ;
        }

        for (int j=0; j<board.size(); j++) {
            if (canplace(i,j, board)) {
                board[i][j] = 'Q';
                dfs(i+1, board, ans);
                board[i][j] = '.';
            }
        }
    }

    bool canplace(int x, int y, vector<string>& soln) {
        int n = soln.size();
        
        for (int i=0; i<x; i++) {
                if ( soln[i][y] == 'Q') {
                    return false;
                }
        }

        for (int i=0; i<n; i++) {
            if (x-i  >= 0 && y-i >= 0) {
                if (soln[x-i][y-i] == 'Q') {
                    return false;
                }
            }

            if (x+i <n && y+i < n) {
                if (soln[x+i][y+i] == 'Q') {
                    return false;
                }
            }

            if (x-i >=0 && y+i < n) {
                if (soln[x-i][y+i] == 'Q') {
                    return false;
                }
            }

            if (x+i <n && y-i >= 0) {
                if (soln[x+i][y-i] == 'Q') {
                    return false;
                }
            }
        }

        return true;
    }
};
