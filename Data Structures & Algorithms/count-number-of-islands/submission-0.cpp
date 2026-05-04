class Solution {
public:
    bool visited[101][101] = {false};
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    fill(grid, i, j);
                }
            }
        }

        return count;
    }

    void fill(vector<vector<char>> grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        visited[x][y] = true;
        if (x+1 < n && !visited[x+1][y] && grid[x+1][y] == '1') {
            fill(grid, x+1, y);
        }

        if (x-1 >= 0 && !visited[x-1][y] && grid[x-1][y] == '1') {
            fill(grid, x-1, y);
        }

        if (y-1 >= 0 && !visited[x][y-1] && grid[x][y-1] == '1') {
            fill(grid, x, y-1);
        }

        if (y+1 < m && !visited[x][y+1] && grid[x][y+1] == '1') {
            fill(grid, x, y+1);
        }
    }
};
