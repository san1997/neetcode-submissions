class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //bfs from all edges , 0 allowed move
        // store 0 visited {x, y}
        // mark board with X
        // mark board with 0 for visited vec

        int m = board.size();
        int n = board[0].size();

        if (m < 3 || n < 3) {
            return ;
        }

        vector<vector<int>> vis(m+1, vector<int>(n+1, 0));

        queue<pair<int, int>> q;

        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][n-1] == 'O'){
                q.push({i, n-1});
            }
        }

        for (int i=1;i<n-1;i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
            }
            if (board[m-1][i] == 'O') {
                q.push({m-1, i});
            }
        }

        while (q.size()) {
            pair<int, int> top = q.front();
            q.pop();

            int x = top.first;
            int y = top.second;

            cout << x << " " << y << endl;
            vis[x][y] = 1;

            if (x+1 < m && board[x+1][y] == 'O' &&  !vis[x+1][y]) {
                q.push({x+1, y});
            }

            if (x-1 >=0 && board[x-1][y] == 'O' && !vis[x-1][y]) {
                q.push({x-1, y});
            }

            if (y-1 >=0 && board[x][y-1] == 'O' && !vis[x][y-1]) {
                q.push({x, y-1});
            }

            if (y+1 < n && board[x][y+1] == 'O' && !vis[x][y+1]) {
                q.push({x, y+1});
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
