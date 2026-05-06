class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size(); 
        
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j< grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dis = 1;
        while (q.size()) {
            queue<pair<int, int>> tmp;

            while(q.size()) {
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;

                cout << x << " " << y << endl;

                if (x-1>=0 && grid[x-1][y] == INT_MAX) {
                    grid[x-1][y] = dis;
                    tmp.push({x-1, y});
                } 

                if (x+1 < m && grid[x+1][y] == INT_MAX) {
                    grid[x+1][y] = dis;
                    tmp.push({x+1, y});
                }

                if (y-1 >= 0 && grid[x][y-1] == INT_MAX) {
                    grid[x][y-1] = dis;
                    tmp.push({x, y-1});
                } 

                if (y+1 < n && grid[x][y+1] == INT_MAX) {
                    grid[x][y+1] = dis;
                    tmp.push({x, y+1});
                }    
            }

            q = tmp;
            dis++;
        }
    }
};
