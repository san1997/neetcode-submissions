class Solution {
public:
    int vis[52][52] = {0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int counter = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    counter++;
                    fill(grid, i, j, counter);
                }
            }
        }

        map<int, int> fre;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                cout << vis[i][j] << " ";
                if (vis[i][j]) {
                    fre[vis[i][j]]++;
                }
            }
            cout << endl;
        }

        int ans =0 ;
        for (auto it=fre.begin(); it!=fre.end(); it++) {
            ans = max(ans, it->second);
        }

        return ans;
    }

    void fill(vector<vector<int>> grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vis[x][y] = k;
        if (x+1 < n && !vis[x+1][y] && grid[x+1][y] == 1) {
            fill(grid, x+1, y, k);
        }

        if (x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] == 1) {
            fill(grid, x-1, y, k);
        }

        if (y-1 >= 0 && !vis[x][y-1] && grid[x][y-1] == 1) {
            fill(grid, x, y-1, k);
        }

        if (y+1 < m && !vis[x][y+1] && grid[x][y+1] == 1) {
            fill(grid, x, y+1, k);
        }
    }
};
