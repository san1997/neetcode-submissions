class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int time[101][101] = {-1};
        for (int i=0; i<101; i++) {
            for (int j=0; j<101; j++) {
                time[i][j] = -1;
            }
        }

        queue<pair<int, int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    time[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int minutes = 1;
        while(q.size()) {
            queue<pair<int, int>> tmp;

            while (q.size()) {
                auto front = q.front();
                int x = front.first;
                int y = front.second;

                cout <<  x << " " << y << " " << minutes << endl;
                q.pop();

                if (x-1 >= 0 && grid[x-1][y] == 1 && time[x-1][y] == -1) {
                    time[x-1][y] = minutes;
                    tmp.push({x-1, y});
                }

                if (x+1 < m && grid[x+1][y] == 1 && time[x+1][y] == -1) {
                    time[x+1][y] = minutes;
                    tmp.push({x+1, y});
                }

                if (y-1 >= 0 && grid[x][y-1] == 1 && time[x][y-1] == -1) {
                    time[x][y-1] = minutes;
                    tmp.push({x, y-1});
                }

                if (y+1 < n && grid[x][y+1] == 1 && time[x][y+1] == -1) {
                    time[x][y+1] = minutes;
                    tmp.push({x, y+1});
                }

            }

            q = tmp;
            minutes++;
        }

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++){
                
                    ans = max(ans, time[i][j]);
                
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++){
                if ( grid[i][j] == 1 && time[i][j] == -1) {
                    ans = -1;
                }
            }
        }

        return ans;
    }
};
