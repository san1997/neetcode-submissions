class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i=0; i < matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (auto it = rows.begin(); it != rows.end(); it++) {
            int x = *it;

            for (int i=0; i<n; i++) {
                matrix[x][i] = 0;
            }
        }

        for (auto it = cols.begin(); it != cols.end(); it++) {
            int y = *it;

            for (int i=0; i<m; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};
