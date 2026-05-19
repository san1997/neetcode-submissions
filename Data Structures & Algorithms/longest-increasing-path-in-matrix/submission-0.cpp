class Solution {
public:
    int dp[104][104] = {-1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int path = findpath(matrix, i, j);
                ans = max(ans, path);
            }
        }

        return ans;
    }

    int findpath(vector<vector<int>>& matrix, int x, int y) {
        int path = 0;
        // cout << x << " " << y << endl;

        if (dp[x][y] > 0) {
            return dp[x][y];
        } 
        
        if (x-1 >= 0 && matrix[x-1][y] > matrix[x][y]) {
            int newpath = findpath(matrix, x-1, y);
            path = max(path, newpath);
        }

        if (x+1 < matrix.size() && matrix[x+1][y] > matrix[x][y]) {
            int newpath = findpath(matrix, x+1, y);
            path = max(path, newpath);
        }

        if (y-1 >=0 && matrix[x][y-1] > matrix[x][y]) {
            int newpath = findpath(matrix, x, y-1);
            path = max(path, newpath);
        }

        if (y+1 < matrix[0].size() && matrix[x][y+1] > matrix[x][y] ) {
            int newpath = findpath(matrix, x, y+1);
            path = max(path, newpath);
        }

        return dp[x][y] = path+1;
    }
};
